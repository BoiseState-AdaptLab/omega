/*****************************************************************************
 Copyright (C) 2005-2011 Chun Chen
 All Rights Reserved.

 Purpose:
   suif IR code wrapper

 Notes:

 History:
   02/01/06 - Chun Chen - created
*****************************************************************************/

#include <code_gen/CG_suifRepr.h>
#include <stdio.h>

namespace omega {

CG_outputRepr* CG_suifRepr::clone() const {
  if (!op_.is_null() ) {
    operand op = const_cast<CG_suifRepr *>(this)->op_.clone();
    return new CG_suifRepr(op);
  }
  else if (tnl_ != NULL) {
    tree_node_list *tnl = tnl_->clone();
    return new CG_suifRepr(tnl);
  }
  else
    return new CG_suifRepr();
}

void CG_suifRepr::clear() {
  if (!op_.is_null()) {
    if (op_.is_instr())
      delete op_.instr();
    op_.set_null();
  }
  else if (tnl_ != NULL) {
    delete tnl_;
    tnl_ = NULL;
  }
}

tree_node_list* CG_suifRepr::GetCode() const {
  return tnl_;
}

operand CG_suifRepr::GetExpression() const {
  return op_;
} 

void CG_suifRepr::dump() const {
  if (tnl_ != NULL)
    tnl_->print();
  else if (!op_.is_null())
    op_.print();
}

}
