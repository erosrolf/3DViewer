#ifndef _3DVIEWER_SRC_CORE_OBJ_MODIFIER_STRATEGY_SCALE_STRATEGY_H_
#define _3DVIEWER_SRC_CORE_OBJ_MODIFIER_STRATEGY_SCALE_STRATEGY_H_

#include "../obj.h"
#include "obj_modifier.h"

namespace s21 {

class Obj;

/**
 * @brief Strategy for scaling a 3D object in on all axes
 */
class ScalingStrategy : public ObjModifier {
 public:
  /**
   * @param s the number by which the object's size is multiplied
   */
  ScalingStrategy(double s) : s_(s) {}

  void modify(Obj& obj) override;

 private:
  double s_;
};

}  // namespace s21

#endif  // _3DVIEWER_SRC_CORE_OBJ_MODIFIER_STRATEGY_SCALE_STRATEGY_H_
