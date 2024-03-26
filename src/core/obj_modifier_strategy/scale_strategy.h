#ifndef _3DVIEWER_SRC_CORE_OBJ_MODIFIER_STRATEGY_SCALE_STRATEGY_H_
#define _3DVIEWER_SRC_CORE_OBJ_MODIFIER_STRATEGY_SCALE_STRATEGY_H_

#include "../obj.h"
#include "obj_modifier.h"

namespace s21 {

class Obj;

class ScalingStrategy : public ObjModifier {
 public:
  ScalingStrategy(double s) : s_(s) {}

  void modify(Obj& obj) override;

 private:
  double s_;
};

}  // namespace s21

#endif  // _3DVIEWER_SRC_CORE_OBJ_MODIFIER_STRATEGY_SCALE_STRATEGY_H_
