/*****************************************************************************
 Copyright (C) 2005-2011 Chun Chen
 All Rights Reserved.

 Purpose:
   generate suif code

 Notes:
     
 History:
   02/01/06 created by Chun Chen
*****************************************************************************/

#include <code_gen/CG_suifBuilder.h>
#include <code_gen/codegen_error.h>
#include <basic/util.h>
#include <stack>
#include <suif1/annote.h>

namespace omega {

//-----------------------------------------------------------------------------
// make suif initilization happy
//-----------------------------------------------------------------------------
char *k_ocg_comment;

// void __attribute__ ((constructor)) my_init(void) {
//   ANNOTE(k_ocg_comment, "omega_comment", TRUE);
// }

const char *libcode_gen_ver_string = "";
const char *libcode_gen_who_string = "";
const char *libcode_gen_suif_string = "";

void init_code_gen(int&, char* []) {
  ANNOTE(k_ocg_comment, "omega_comment", TRUE);
}

void exit_code_gen(void) {
}


//-----------------------------------------------------------------------------
// Class: CG_suifBuilder
//-----------------------------------------------------------------------------

CG_outputRepr *CG_suifBuilder::CreateSubstitutedStmt (int, CG_outputRepr *stmt,
                                                      const std::vector<std::string> &vars,
                                                      std::vector<CG_outputRepr *> &subs) const {
  tree_node_list *tnl = static_cast<CG_suifRepr *>(stmt)->tnl_;
  delete stmt;

  for (int i = 0; i < subs.size(); i++) {
    if (subs[i] == NULL)
      continue;
    
    CG_suifRepr *repr = static_cast<CG_suifRepr *>(subs[i]);
    operand op = repr->op_;
    delete repr;

    var_sym *vs = static_cast<var_sym *>(symtab_->lookup_sym(vars[i].c_str(), SYM_VAR));

    substitute(tnl, vs, op, symtab_);

    if (op.is_instr())
      delete op.instr();
  }
  
  return new CG_suifRepr(tnl);
}


CG_outputRepr *CG_suifBuilder::CreateAssignment(int, CG_outputRepr *lhs,
                                                CG_outputRepr *rhs) const {
  operand src = static_cast<CG_suifRepr *>(rhs)->op_;
  if (src.is_instr() && src.instr()->opcode() == io_array) {
    in_array *ia = static_cast<in_array *>(src.instr());
    instruction *ins = new in_rrr(io_lod, ia->elem_type(), operand(), ia);
    src = operand(ins);
  }

  instruction *ins;
  operand dst = static_cast<CG_suifRepr *>(lhs)->op_;
  if (dst.is_instr() && dst.instr()->opcode() == io_array) {
    in_array *ia = static_cast<in_array *>(dst.instr());
    ins = new in_rrr(io_str, type_void, operand(), operand(ia), src);
  }
  else
    ins = new in_rrr(io_cpy, src.type(), dst, src);
  
  delete lhs;
  delete rhs;

  tree_node_list *tnl = new tree_node_list;
  tnl->append(new tree_instr(ins));

  return new CG_suifRepr(tnl);
}


CG_outputRepr *CG_suifBuilder::CreateInvoke(const std::string &funcName,
                                            std::vector<CG_outputRepr *> &list) const {
  if (funcName == std::string("max") || funcName == std::string("min")) {
    if (list.size() == 0) {
      return NULL;
    }
    else if (list.size() == 1) {
      return list[0];
    }
    else {
      int last = list.size() - 1;
      operand op2 = static_cast<CG_suifRepr *>(list[last])->op_;
      delete list[last];
      list.erase(list.end()-1);
      CG_suifRepr *repr = static_cast<CG_suifRepr *>(CreateInvoke(funcName, list));
      operand op1 = repr->op_;

      instruction *ins;
      if (funcName == std::string("max"))
        ins = new in_rrr(io_max, op1.type(), operand(), op1, op2);
      else
        ins = new in_rrr(io_min, op1.type(), operand(), op1, op2);

      repr->op_ = operand(ins);
      
      return repr;
    }
  }
  else
    throw codegen_error("invoke function " + funcName + " not implemented");
}


CG_outputRepr *CG_suifBuilder::CreateComment(int, const std::string &commentText) const {
  if (commentText == std::string("")) {
    return NULL;
  }

  instruction *ins = new in_rrr(io_mrk);

  immed_list *iml = new immed_list;
  iml->append(immed(const_cast<char *>(commentText.c_str())));
  ins->prepend_annote(k_ocg_comment, iml);
  
  tree_node_list *tnl = new tree_node_list;
  tnl->append(new tree_instr(ins));

  return new CG_suifRepr(tnl);
}


CG_outputRepr *CG_suifBuilder::CreateIf(int, CG_outputRepr *guardList,
                                        CG_outputRepr *true_stmtList, CG_outputRepr *false_stmtList) const {
  static int if_counter = 1;
  std::string s = std::string("omegaif_") + to_string(if_counter++);
  label_sym *if_label = new label_sym(const_cast<char *>(s.c_str()));
  symtab_->add_sym(if_label);
  
  if (true_stmtList == NULL && false_stmtList == NULL) {
    delete guardList;
    return NULL;
  }

  tree_node_list *header = new tree_node_list;
  operand op = static_cast<CG_suifRepr *>(guardList)->op_;

  std::stack<void *> S;
  S.push(op.instr());
  while(!S.empty()) {
    instruction *ins = static_cast<instruction *>(S.top());
    S.pop();
    if (ins->opcode() == io_and) {
      instruction *ins1 = ins->src_op(0).instr();
      ins1->remove();
      S.push(ins1);
      instruction *ins2 = ins->src_op(1).instr();
      ins2->remove();
      S.push(ins2);
      delete ins;
    }
    else {
      ins = new in_bj(io_bfalse, if_label, operand(ins));
      header->append(new tree_instr(ins));
    }
  }

  tree_node_list *then_part, *else_part;
  if (true_stmtList != NULL)
    then_part = static_cast<CG_suifRepr *>(true_stmtList)->tnl_;
  else
    then_part = NULL;
  if (false_stmtList != NULL)
    else_part = static_cast<CG_suifRepr *>(false_stmtList)->tnl_;
  else
    else_part = NULL;
  tree_if *ti = new tree_if(if_label, header, then_part, else_part);

  tree_node_list *tnl = new tree_node_list;
  tnl->append(ti);

  delete guardList;
  delete true_stmtList;
  delete false_stmtList;

  return new CG_suifRepr(tnl);
}


CG_outputRepr *CG_suifBuilder::CreateInductive(CG_outputRepr *index,
                                               CG_outputRepr *lower,
                                               CG_outputRepr *upper,
                                               CG_outputRepr *step) const {
  var_sym *index_sym = static_cast<CG_suifRepr *>(index)->op_.symbol();
  operand lower_bound = static_cast<CG_suifRepr *>(lower)->op_;
  operand upper_bound = static_cast<CG_suifRepr *>(upper)->op_;
  operand step_size = static_cast<CG_suifRepr *>(step)->op_;

  label_sym *contLabel = new label_sym("");
  label_sym *brkLabel = new label_sym("");
  symtab_->add_sym(contLabel);
  symtab_->add_sym(brkLabel);
  tree_for *tf = new tree_for(index_sym, FOR_SLTE, contLabel, brkLabel, NULL,
                              lower_bound, upper_bound, step_size, NULL);

  tree_node_list *tnl = new tree_node_list;
  tnl->append(tf);

  delete index;
  delete lower;
  delete upper;
  delete step;

  return new CG_suifRepr(tnl);
}


CG_outputRepr *CG_suifBuilder::CreateLoop(int, CG_outputRepr *control,
                                          CG_outputRepr *stmtList) const {
  if (stmtList == NULL) {
    delete control;
    return NULL;
  }
  else if (control == NULL)
    return stmtList;

  tree_node_list *tnl = static_cast<CG_suifRepr *>(control)->tnl_;
  tree_node_list_iter iter(tnl);
  tree_for *tf = static_cast<tree_for *>(iter.step());
  
  tree_node_list *body = static_cast<CG_suifRepr *>(stmtList)->tnl_;
  tf->set_body(body);

  delete stmtList;

  return control;
}


CG_outputRepr *CG_suifBuilder::CreateInt(int num) const {
  in_ldc *ins = new in_ldc(type_s32, operand(), immed(num));
  
  return new CG_suifRepr(operand(ins));
}


CG_outputRepr *CG_suifBuilder::CreateIdent(const std::string &varName) const {
  if (varName == std::string("")) {
    return NULL;
  }

  var_sym *vs = static_cast<var_sym*>(symtab_->lookup_sym(varName.c_str(), SYM_VAR));

  if (vs == NULL) {
    vs = new var_sym(type_s32, const_cast<char*>(varName.c_str()));
    symtab_->add_sym(vs);
  }
                                                 
  return new CG_suifRepr(operand(vs));
}


CG_outputRepr *CG_suifBuilder::CreatePlus(CG_outputRepr *lop,
                                          CG_outputRepr *rop) const {
  if (rop == NULL) {
    return lop;
  }
  else if (lop == NULL) {
    return rop;
  }

  operand op1 = static_cast<CG_suifRepr *>(lop)->op_;
  operand op2 = static_cast<CG_suifRepr *>(rop)->op_;

  instruction *ins = new in_rrr(io_add, op1.type(), operand(), op1, op2);

  delete lop;
  delete rop;
  
  return new CG_suifRepr(operand(ins));
}


CG_outputRepr *CG_suifBuilder::CreateMinus(CG_outputRepr *lop,
                                           CG_outputRepr *rop) const {
  if (rop == NULL) {
    return lop;
  }
  else if (lop == NULL) {
    operand op = static_cast<CG_suifRepr *>(rop)->op_;
    instruction *ins = new in_rrr(io_neg, op.type(), operand(), op);

    delete rop;
      
    return new CG_suifRepr(operand(ins));
  }
  else {
    operand op1 = static_cast<CG_suifRepr *>(lop)->op_;
    operand op2 = static_cast<CG_suifRepr *>(rop)->op_;

    instruction *ins = new in_rrr(io_sub, op1.type(), operand(), op1, op2);

    delete lop;
    delete rop;
  
    return new CG_suifRepr(operand(ins));
  }
}


CG_outputRepr *CG_suifBuilder::CreateTimes(CG_outputRepr *lop,
                                           CG_outputRepr *rop) const {
  if (rop == NULL || lop == NULL) {
    if (rop != NULL) {
      rop->clear();
      delete rop;
    }
    if (lop != NULL) {
      lop->clear();
      delete lop;
    }
    return NULL;
  }

  operand op1 = static_cast<CG_suifRepr *>(lop)->op_;
  operand op2 = static_cast<CG_suifRepr *>(rop)->op_;

  instruction *ins = new in_rrr(io_mul, op1.type(), operand(), op1, op2);

  delete lop;
  delete rop;
  
  return new CG_suifRepr(operand(ins));
}


CG_outputRepr *CG_suifBuilder::CreateIntegerFloor(CG_outputRepr *lop,
                                                  CG_outputRepr *rop) const {
  if (rop == NULL)
    throw codegen_error("integer division by zero");
  else if (lop == NULL) {
    delete rop;
    return NULL;
  }

  operand op1 = static_cast<CG_suifRepr *>(lop)->op_;
  operand op2 = static_cast<CG_suifRepr *>(rop)->op_;

  // bugs in SUIF prevent use of correct io_divfloor
  instruction *ins = new in_rrr(io_div, op1.type(), operand(), op1, op2);

  delete lop;
  delete rop;
  
  return new CG_suifRepr(operand(ins));
}


CG_outputRepr *CG_suifBuilder::CreateIntegerMod(CG_outputRepr *lop,
                                                CG_outputRepr *rop) const {
  if (rop == NULL)
    throw codegen_error("integer modulo by zero");
  else if (lop == NULL) {
    delete rop;
    return NULL;
  }

  operand op1 = static_cast<CG_suifRepr *>(lop)->op_;
  operand op2 = static_cast<CG_suifRepr *>(rop)->op_;

  // bugs in SUIF prevent use of correct io_mod
  instruction *ins = new in_rrr(io_rem, type_s32, operand(), op1, op2);

  delete lop;
  delete rop;
  
  return new CG_suifRepr(operand(ins));
}


CG_outputRepr *CG_suifBuilder::CreateAnd(CG_outputRepr *lop,
                                         CG_outputRepr *rop) const {
  if (rop == NULL)
    return lop;
  else if (lop == NULL)
    return rop;
  
  operand op1 = static_cast<CG_suifRepr *>(lop)->op_;
  operand op2 = static_cast<CG_suifRepr *>(rop)->op_;

  instruction *ins = new in_rrr(io_and, op1.type(), operand(), op1, op2);

  delete lop;
  delete rop;
  
  return new CG_suifRepr(operand(ins));
}


CG_outputRepr *CG_suifBuilder::CreateLE(CG_outputRepr *lop,
                                        CG_outputRepr *rop) const {
  operand op1 = static_cast<CG_suifRepr *>(lop)->op_;
  operand op2 = static_cast<CG_suifRepr *>(rop)->op_;

  instruction *ins = new in_rrr(io_sle, type_s32, operand(), op1, op2);

  delete lop;
  delete rop;
  
  return new CG_suifRepr(operand(ins));
}


CG_outputRepr *CG_suifBuilder::CreateEQ(CG_outputRepr *lop,
                                        CG_outputRepr *rop) const {
  operand op1 = static_cast<CG_suifRepr *>(lop)->op_;
  operand op2 = static_cast<CG_suifRepr *>(rop)->op_;

  instruction *ins = new in_rrr(io_seq, type_s32, operand(), op1, op2);

  delete lop;
  delete rop;
  
  return new CG_suifRepr(operand(ins));
}



CG_outputRepr *CG_suifBuilder::StmtListAppend(CG_outputRepr *list1, 
                                              CG_outputRepr *list2) const {
  if (list2 == NULL) {
    return list1;
  }
  else if (list1 == NULL) {
    return list2;
  }

  tree_node_list *tnl1 = static_cast<CG_suifRepr *>(list1)->tnl_;
  tree_node_list *tnl2 = static_cast<CG_suifRepr *>(list2)->tnl_;
  if (tnl2 == NULL)
    tnl1->append(new tree_instr(static_cast<CG_suifRepr *>(list2)->op_.instr()));
  else
    tnl1->append(tnl2);

  delete list2;

  return list1;
}


//-----------------------------------------------------------------------------
// suif utility
//-----------------------------------------------------------------------------

bool substitute(instruction *in, var_sym *sym, operand expr, base_symtab *st) {
  if (in == NULL || sym == NULL)
    return false;

  bool r = false;
  for (unsigned i = 0; i < in->num_srcs(); i++) {
    operand op(in->src_op(i));

    if (op.is_symbol() && op.symbol() == sym) {
      in->set_src_op(i, expr.clone(st));
      r = true;
    }
    else if (op.is_instr()) {
      r = substitute(op.instr(), sym, expr, st) || r;
    }
  }

  return r;
}

bool substitute(tree_node *tn, var_sym *sym, operand expr, base_symtab *st) {
  if (tn == NULL)
    return false;

  bool r = false;
  if (tn->kind() == TREE_INSTR)
    r = substitute(static_cast<tree_instr*>(tn)->instr(), sym, expr, st) || r;
  else {
    for (unsigned i = 0; i < tn->num_child_lists(); i++) {
      r = substitute(tn->child_list_num(i), sym, expr, st) || r;
    }
  }

  return r;
}

bool substitute(tree_node_list *tnl, var_sym *sym, operand expr,
                base_symtab *st) {
  if (tnl == NULL)
    return false;

  bool r = false;
  tree_node_list_iter iter(tnl);
  while (!iter.is_empty()) {
    tree_node *tn = iter.step();

    r = substitute(tn, sym, expr, st) || r;
  }

  return r;
}

}
