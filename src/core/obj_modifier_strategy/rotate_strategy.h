#ifndef _3DVIEWER_SRC_CORE_OBJ_MODIFIER_STRATEGY_ROTATE_STRATEGY_H_
#define _3DVIEWER_SRC_CORE_OBJ_MODIFIER_STRATEGY_ROTATE_STRATEGY_H_

#include "../obj.h"
#include "obj_modifier.h"

namespace s21 {

class Obj;

/**
 * @class RotateStrategy
 * @brief Strategy for rotating a 3D object around a specified axis.
 */
class RotateStrategy : public ObjModifier {
 public:
  /**
   * @enum Type
   * @brief Enumeration for the axis of rotation.
   */
  enum class Type {
    X = 0,  ///< Rotate around the X-axis.
    Y,      ///< Rotate around the Y-axis.
    Z,      ///< Rotate around the Z-axis.
  };

  /**
   * @brief Constructor for rotation strategy.
   * @param type Axis of rotation.
   * @param angle Angle of rotation.
   */
  RotateStrategy(Type type, double angle) : type_(type), angle_(angle) {}

  /**
   * @brief Applies rotation to the object
   * @param obj Reference to the object to be rotated.
   */
  void modify(Obj& obj) override;

 private:
  using RotateFunction = void (RotateStrategy::*)(Vertex_3d&, double, double);

  void rotate(Obj& obj, double angle, RotateFunction rotateFunc);
  void rotateX(Vertex_3d& vertex, double sin_angle, double cos_angle);
  void rotateY(Vertex_3d& vertex, double sin_angle, double cos_angle);
  void rotateZ(Vertex_3d& vertex, double sin_angle, double cos_angle);

  Type type_;     ///< Axis of rotation.
  double angle_;  ///< Angle of rotation in degrees.
};

}  // namespace s21

#endif  // _3DVIEWER_SRC_CORE_OBJ_MODIFIER_STRATEGY_ROTATE_STRATEGY_H_
