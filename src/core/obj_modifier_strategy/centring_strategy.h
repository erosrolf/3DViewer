#ifndef _3DVIEWER_SRC_CORE_OBJ_MODIFIER_STRATEGY_CENTRING_STRATEGY_H_
#define _3DVIEWER_SRC_CORE_OBJ_MODIFIER_STRATEGY_CENTRING_STRATEGY_H_

#include "../obj.h"
#include "obj_modifier.h"

namespace s21 {

class Obj;
/**
 * @class CentringStrategy
 * @brief Strategy for centring a 3D object within its bounding box.
 */
class CentringStrategy : public ObjModifier {
 public:
  /**
   * @brief Centers the object.
   * @param obj Reference to the object to be centered.
   */
  void modify(Obj& obj) override;
};
}  // namespace s21

#endif  // _3DVIEWER_SRC_CORE_OBJ_MODIFIER_STRATEGY_CENTRING_STRATEGY_H_
