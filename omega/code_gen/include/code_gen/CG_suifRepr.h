#ifndef _CG_SUIFREPR_H
#define _CG_SUIFREPR_H

#include <code_gen/CG_outputRepr.h>
#include <suif1.h>

namespace omega {

class CG_suifRepr: public CG_outputRepr {
private:
  // only one of tnl_ and op_ would be active at any time, depending on
  // whether it is building a statement list or an expression tree
  tree_node_list *tnl_;
  operand op_;

public:
  CG_suifRepr(): tnl_(NULL), op_() {}
  CG_suifRepr(tree_node_list *tnl): tnl_(tnl), op_() {}
  CG_suifRepr(operand op): tnl_(NULL), op_(op) {}
  ~CG_suifRepr() { /* tnl_ and op_ should be grafted to other expression tree or statement list */ }
  CG_outputRepr *clone() const;
  void clear();
  void dump() const;

  //---------------------------------------------------------------------------
  // basic operation
  //---------------------------------------------------------------------------
  tree_node_list *GetCode() const;
  operand GetExpression() const;
  
  friend class CG_suifBuilder;
};

}

#endif
