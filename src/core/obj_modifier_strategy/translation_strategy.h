#ifndef _3DVIEWER_SRC_CORE_OBJ_MODIFIER_STRATEGY_TRANSLATION_STRATEGY_H_
#define _3DVIEWER_SRC_CORE_OBJ_MODIFIER_STRATEGY_TRANSLATION_STRATEGY_H_

#include "../obj.h"
#include "obj_modifier.h"

namespace s21 {

class Obj;

class TranslationStrategy : public ObjModifier {
  /**
   * @brief Strategy for translation a 3D object
   */
 public:
  /**
   * @param x the number by which all points will move along the X axis
   * @param y the number by which all points will move along the Y axis
   * @param z the number by which all points will move along the Z axis
   */
  TranslationStrategy(double x, double y, double z);

  void modify(Obj& obj) override;

 private:
  double x_, y_, z_;
};

}  // namespace s21

#endif  // _3DVIEWER_SRC_MODEL_OBJ_MODIFIER_STRATEGY_TRANSLATION_STRATEGY_H_
