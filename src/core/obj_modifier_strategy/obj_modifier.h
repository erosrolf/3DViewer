#ifndef _3DVIEWER_SRC_CORE_OBJ_MODIFIER_STRATEGY_OBJ_MODIFIER_H_
#define _3DVIEWER_SRC_CORE_OBJ_MODIFIER_STRATEGY_OBJ_MODIFIER_H_

#include "../obj.h"

namespace s21 {

class Obj;

/**
 * @class ObjModifier
 * @brief Abstract base class for object modification strategies.
 */
class ObjModifier {
 public:
  virtual ~ObjModifier() = default;

  /**
   * @brief Modify the given 3D object.
   * @param obj Reference to the object to be modified.
   */
  virtual void modify(Obj& obj) = 0;
};
}  // namespace s21

#endif  // _3DVIEWER_SRC_CORE_OBJ_MODIFIER_STRATEGY_OBJ_MODIFIER_H_
