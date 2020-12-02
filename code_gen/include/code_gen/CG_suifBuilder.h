#ifndef _CG_SUIFBUILDER_H
#define _CG_SUIFBUILDER_H

#include <code_gen/CG_outputBuilder.h>
#include <code_gen/CG_suifRepr.h>

namespace omega {

class CG_suifBuilder: public CG_outputBuilder { 
private:
  proc_symtab *symtab_;

public:
  CG_suifBuilder(proc_symtab *symtab) {symtab_ = symtab;}
  ~CG_suifBuilder() {}

  CG_outputRepr *CreateSubstitutedStmt(int, CG_outputRepr *stmt, const std::vector<std::string> &vars, std::vector<CG_outputRepr *> &subs) const;
  CG_outputRepr *CreateAssignment(int, CG_outputRepr *lhs, CG_outputRepr *rhs) const;
  CG_outputRepr *CreateInvoke(const std::string &funcName, std::vector<CG_outputRepr *> &argList) const;
  CG_outputRepr *CreateComment(int, const std::string &commentText) const;
  CG_outputRepr *CreateIf(int, CG_outputRepr *guardCondition, CG_outputRepr *true_stmtList, CG_outputRepr *false_stmtList) const;
  CG_outputRepr *CreateInductive(CG_outputRepr *index, CG_outputRepr *lower, CG_outputRepr *upper, CG_outputRepr *step) const;
  CG_outputRepr *CreateLoop(int, CG_outputRepr *control, CG_outputRepr *stmtList) const;
  CG_outputRepr *CreateInt(int num) const;
  CG_outputRepr *CreateIdent(const std::string &varName) const;
  CG_outputRepr *CreatePlus(CG_outputRepr *lop, CG_outputRepr *rop) const;
  CG_outputRepr *CreateMinus(CG_outputRepr *lop, CG_outputRepr *rop) const;
  CG_outputRepr *CreateTimes(CG_outputRepr *lop, CG_outputRepr *rop) const;
  CG_outputRepr *CreateIntegerFloor(CG_outputRepr *lop, CG_outputRepr *rop) const;
  CG_outputRepr *CreateIntegerMod(CG_outputRepr *lop, CG_outputRepr *rop) const;
  CG_outputRepr *CreateAnd(CG_outputRepr *lop, CG_outputRepr *rop) const;
  CG_outputRepr *CreateLE(CG_outputRepr *lop, CG_outputRepr *rop) const;
  CG_outputRepr *CreateEQ(CG_outputRepr *lop, CG_outputRepr *rop) const;
  CG_outputRepr *StmtListAppend(CG_outputRepr *list1, CG_outputRepr *list2) const;
};

extern char *k_ocg_comment;

bool substitute(instruction *in, var_sym *sym, operand expr,
                base_symtab *st=NULL);
bool substitute(tree_node *tn, var_sym *sym, operand expr,
                base_symtab *st=NULL);
bool substitute(tree_node_list *tnl, var_sym *sym, operand expr,
                base_symtab *st = NULL);

}

#endif
