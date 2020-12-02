/*****************************************************************************
 Copyright (C) 1994-2000 the Omega Project Team
 Copyright (C) 2005-2011 Chun Chen
 All Rights Reserved.

 Purpose:
   generate pseudo string code

 Notes:
   There is no need to check illegal NULL parameter and throw invalid_argument
 in other IR interface implementation. They are for debugging purpose.
   intMod implements modular function that returns positve remainder no matter
 lop is postive or nagative and rop is guranteed to be positive here.
     
 History:
   04/17/96 - Lei Zhou - created
   08/31/09 add parenthesis to string operands, Chun Chen
*****************************************************************************/

#include <code_gen/CG_stringBuilder.h>
#include <code_gen/codegen_error.h>
#include <basic/util.h>
#include <string>
#include <stdexcept>


namespace {

std::string SafeguardString(const std::string &s, char op) {
  int len = s.length();
  int paren_level = 0;
  int num_plusminus = 0;
  int num_mul = 0;
  int num_div = 0;
  for (int i = 0; i < len; i++)
    switch (s[i]) {
    case '(':
      paren_level++;
      break;
    case ')':
      paren_level--;
      break;
    case '+':
    case '-':
      if (paren_level == 0)
        num_plusminus++;
      break;
    case '*':
      if (paren_level == 0)
        num_mul++;
      break;
    case '/':
      if (paren_level == 0)
        num_div++;
      break;
    default:
      break;
    }

  bool need_paren = false;
  switch (op) {
  case '-':
    if (num_plusminus > 0)
      need_paren = true;
    break;
  case '*':
    if (num_plusminus > 0 || num_div > 0)
      need_paren = true;
    break;
  case '/':
    if (num_plusminus > 0 || num_div > 0 || num_mul > 0)
      need_paren = true;
    break;
  default:
    break;
  }

  if (need_paren)
    return "(" + s + ")";
  else
    return s;
}


std::string GetIndentSpaces(int indent) {
  std::string indentStr;
  for (int i = 1; i < indent; i++) {
    indentStr += "  ";
  }
  return indentStr;
}


// A shortcut to extract the string enclosed in the CG_outputRepr and delete
// the original holder.
std::string GetString(omega::CG_outputRepr *repr) {
  std::string result = static_cast<omega::CG_stringRepr *>(repr)->GetString();
  delete repr;
  return result;
}

}


namespace omega {



//-----------------------------------------------------------------------------
// Class: CG_stringBuilder
//-----------------------------------------------------------------------------

CG_stringRepr *CG_stringBuilder::CreateSubstitutedStmt(int indent, CG_outputRepr *stmt,
                                                       const std::vector<std::string> &vars,
                                                       std::vector<CG_outputRepr *> &subs) const {
  std::string listStr = "";

  for (int i = 0; i < subs.size(); i++) {
    if (subs[i] == NULL)
      listStr += "N/A";
    else 
      listStr += GetString(subs[i]);
    if (i < subs.size() - 1)
      listStr += ",";
  } 

  std::string stmtName = GetString(stmt);
  std::string indentStr = GetIndentSpaces(indent);

  return new CG_stringRepr(indentStr + stmtName + "(" + listStr + ");\n");
}

CG_stringRepr *CG_stringBuilder::CreateAssignment(int indent, 
                                                  CG_outputRepr *lhs,
                                                  CG_outputRepr *rhs) const {
  if (lhs == NULL || rhs == NULL)
    throw std::invalid_argument("missing lhs or rhs in assignment");

  std::string lhsStr = GetString(lhs);
  std::string rhsStr = GetString(rhs);

  std::string indentStr = GetIndentSpaces(indent);

  return new CG_stringRepr(indentStr + lhsStr + "=" + rhsStr + ";\n");
}


CG_stringRepr *CG_stringBuilder::CreateInvoke(const std::string &funcName,
                                              std::vector<CG_outputRepr *> &list) const {
  std::string listStr = "";

  for (int i = 0; i < list.size(); i++) {
    listStr += GetString(list[i]);
    if ( i < list.size()-1)
      listStr += ",";
  }

  return new CG_stringRepr(funcName + "(" + listStr + ")");
}
    

CG_stringRepr *CG_stringBuilder::CreateComment(int indent, const std::string &commentText) const {
  if (commentText == std::string("")) {
    return NULL;
  }

  std::string indentStr = GetIndentSpaces(indent);

  return new CG_stringRepr(indentStr + "// " + commentText + "\n");
}


CG_stringRepr *CG_stringBuilder::CreateIf(int indent, CG_outputRepr *guardList,
                                          CG_outputRepr *true_stmtList, CG_outputRepr *false_stmtList) const {
  if (guardList == NULL)
    throw std::invalid_argument("missing if condition");
  
  if (true_stmtList == NULL && false_stmtList == NULL) {
    delete guardList;
    return NULL;
  }

  std::string guardListStr = GetString(guardList);
  std::string indentStr = GetIndentSpaces(indent);
  std::string s;
  if (true_stmtList != NULL && false_stmtList == NULL) {
    s = indentStr + "if (" + guardListStr + ") {\n"
      + GetString(true_stmtList)
      + indentStr + "}\n";
  }
  else if (true_stmtList == NULL && false_stmtList != NULL) {
    s = indentStr + "if !(" + guardListStr + ") {\n"
      + GetString(false_stmtList)
      + indentStr + "}\n";
  }
  else {
    s = indentStr + "if (" + guardListStr + ") {\n" 
      + GetString(true_stmtList)
      + indentStr + "}\n"
      + indentStr + "else {\n"
      + GetString(false_stmtList)
      + indentStr + "}\n";
  }
  
  return new CG_stringRepr(s);
}


CG_stringRepr *CG_stringBuilder::CreateInductive(CG_outputRepr *index,
                                                 CG_outputRepr *lower, CG_outputRepr *upper,
                                                 CG_outputRepr *step) const {
  if (index == NULL)
    throw std::invalid_argument("missing loop index");
  if (lower == NULL)
    throw std::invalid_argument("missing loop lower bound");
  if (upper == NULL)
    throw std::invalid_argument("missing loop upper bound");
  if (step == NULL)
    throw std::invalid_argument("missing loop step size");
  
  std::string indexStr = GetString(index);
  std::string lowerStr = GetString(lower);
  std::string upperStr = GetString(upper);

  std::string doStr = "for(" + indexStr + " = " + lowerStr + "; "
    + indexStr + " <= " + upperStr + "; " 
    + indexStr;
  
  std::string stepStr = GetString(step);
  if (stepStr == to_string(1))
    doStr += "++";
  else
    doStr += " += " + stepStr;
        
  doStr += ")";
      
  return new CG_stringRepr(doStr);
}


CG_stringRepr *CG_stringBuilder::CreateLoop(int indent, CG_outputRepr *control,
                                            CG_outputRepr *stmtList) const {
  if (stmtList == NULL) {
    delete control;
    return NULL;
  }
  else if (control == NULL)
    return static_cast<CG_stringRepr *>(stmtList);

  std::string ctrlStr = GetString(control);
  std::string stmtStr = GetString(stmtList);

  std::string indentStr = GetIndentSpaces(indent);

  std::string s = indentStr + ctrlStr + " {\n"
    + stmtStr 
    + indentStr + "}\n";

  return new CG_stringRepr(s);
}


CG_stringRepr *CG_stringBuilder::CreateInt(int num) const {
  std::string s = to_string(num);
  return new CG_stringRepr(s);
}


CG_stringRepr *CG_stringBuilder::CreateIdent(const std::string &varName) const {
  if (varName == std::string("")) {
    return NULL;
  }

  return new CG_stringRepr(varName);
}


CG_stringRepr *CG_stringBuilder::CreatePlus(CG_outputRepr *lop, CG_outputRepr *rop) const {
  if (rop == NULL) {
    return static_cast<CG_stringRepr *>(lop);
  }
  else if (lop == NULL) {
    return static_cast<CG_stringRepr *>(rop);
  }

  std::string lopStr = GetString(lop);
  std::string ropStr = GetString(rop);

  return new CG_stringRepr(lopStr + "+" + ropStr);
}


CG_stringRepr *CG_stringBuilder::CreateMinus(CG_outputRepr *lop, CG_outputRepr *rop) const {
  if (rop == NULL) {
    return static_cast<CG_stringRepr *>(lop);
  }
  else if (lop == NULL) {
    std::string ropStr = GetString(rop);
    return new CG_stringRepr("-" + SafeguardString(ropStr, '-'));
  }

  std::string lopStr = GetString(lop);
  std::string ropStr = GetString(rop);

  return new CG_stringRepr(lopStr + "-" + SafeguardString(ropStr, '-'));
}


CG_stringRepr *CG_stringBuilder::CreateTimes(CG_outputRepr *lop, CG_outputRepr *rop) const {
  if (rop == NULL || lop == NULL) {
    delete rop;
    delete lop;
    return NULL;
  }

  std::string lopStr = GetString(lop);
  std::string ropStr = GetString(rop);

  return new CG_stringRepr(SafeguardString(lopStr, '*') + "*" + SafeguardString(ropStr, '*'));
}


CG_stringRepr *CG_stringBuilder::CreateDivide(CG_outputRepr *lop, CG_outputRepr *rop) const {
  if (rop == NULL)
    throw codegen_error("integer division by zero");
  else if (lop == NULL) {
    delete rop;
    return NULL;
  }

  std::string lopStr = GetString(lop);
  std::string ropStr = GetString(rop);

  return new CG_stringRepr(SafeguardString(lopStr, '/') + "/" + SafeguardString(ropStr, '/'));
}


CG_stringRepr *CG_stringBuilder::CreateIntegerFloor(CG_outputRepr *lop, CG_outputRepr *rop) const {
  if (rop == NULL)
    throw codegen_error("integer division by zero");
  else if (lop == NULL) {
    delete rop;
    return NULL;
  }

  std::string lopStr = GetString(lop);
  std::string ropStr = GetString(rop);

  return new CG_stringRepr("intFloor(" + lopStr + "," + ropStr + ")");
}


CG_stringRepr *CG_stringBuilder::CreateIntegerMod(CG_outputRepr *lop, CG_outputRepr *rop) const {
  if (rop == NULL)
    throw codegen_error("integer modulo by zero");
  else if (lop == NULL) {
    delete rop;
    return NULL;
  }

  std::string lopStr = GetString(lop);
  std::string ropStr = GetString(rop);

  return new CG_stringRepr("intMod(" + lopStr + "," + ropStr + ")");
}

CG_stringRepr *CG_stringBuilder::CreateIntegerCeil(CG_outputRepr *lop, CG_outputRepr *rop) const {
  if (rop == 0)
    throw codegen_error("integer ceiling by zero");
  else if (lop == NULL) {
    delete rop;
    return NULL;
  }

  std::string lopStr = GetString(lop);
  std::string ropStr = GetString(rop);

  return new CG_stringRepr("intCeil(" + lopStr + "," + ropStr + ")");
}


CG_stringRepr *CG_stringBuilder::CreateAnd(CG_outputRepr *lop, CG_outputRepr *rop) const {
  if (rop == NULL)
    return static_cast<CG_stringRepr *>(lop);
  else if (lop == NULL)
    return static_cast<CG_stringRepr *>(rop);

  std::string lopStr = GetString(lop);
  std::string ropStr = GetString(rop);

  return new CG_stringRepr(lopStr + " && " + ropStr);
}


CG_stringRepr *CG_stringBuilder::CreateGE(CG_outputRepr *lop, CG_outputRepr *rop) const {
  if (rop == NULL || lop == NULL)
    throw std::invalid_argument("missing operand in greater than equal comparison condition");

  std::string lopStr = GetString(lop);
  std::string ropStr = GetString(rop);

  return new CG_stringRepr(lopStr + " >= " + ropStr);
}


CG_stringRepr *CG_stringBuilder::CreateLE(CG_outputRepr *lop, CG_outputRepr *rop) const {
  if (rop == NULL || lop == NULL)
    throw std::invalid_argument("missing operand in less than equal comparison condition");

  std::string lopStr = GetString(lop);
  std::string ropStr = GetString(rop);

  return new CG_stringRepr(lopStr + " <= " + ropStr);
}


CG_stringRepr *CG_stringBuilder::CreateEQ(CG_outputRepr *lop, CG_outputRepr *rop) const {
  if (rop == NULL || lop == NULL)
    throw std::invalid_argument("missing operand in equal comparison condition");

  std::string lopStr = GetString(lop);
  std::string ropStr = GetString(rop);

  return new CG_stringRepr(lopStr + " == " + ropStr);
}



CG_stringRepr *CG_stringBuilder::StmtListAppend(CG_outputRepr *list1, CG_outputRepr *list2) const {
  if (list2 == NULL) {
    return static_cast<CG_stringRepr *>(list1);
  }
  else if (list1 == NULL) {
    return static_cast<CG_stringRepr *>(list2);
  }

  std::string list1Str = GetString(list1);
  std::string list2Str = GetString(list2);

  return new CG_stringRepr(list1Str + list2Str);
}

}
