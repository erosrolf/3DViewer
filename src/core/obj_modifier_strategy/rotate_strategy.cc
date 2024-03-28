#include "rotate_strategy.h"

#include <cmath>

#include "../obj.h"

namespace s21 {

void RotateStrategy::modify(Obj& obj) {
  if (angle_ != 0.0) {
    switch (type_) {
      case Type::X: {
        rotate(obj, angle_, &RotateStrategy::rotateX);
        return;
      }
      case Type::Y: {
        rotate(obj, angle_, &RotateStrategy::rotateY);
        return;
      }
      case Type::Z: {
        rotate(obj, angle_, &RotateStrategy::rotateZ);
        return;
      }
    }
  }
}

void RotateStrategy::rotate(Obj& obj, double angle, RotateFunction rotateFunc) {
  double rad = angle * M_PI / 180.0;
  double cos_angle = cos(rad);
  double sin_angle = sin(rad);

  for (auto& vertex : obj.vertexes) {
    (this->*rotateFunc)(vertex, sin_angle, cos_angle);
  }
  (this->*rotateFunc)(obj.center, sin_angle, cos_angle);
}

void RotateStrategy::rotateX(Vertex_3d& vertex, double sin_angle,
                             double cos_angle) {
  double new_y = vertex.y * cos_angle - vertex.z * sin_angle;
  double new_z = vertex.y * sin_angle + vertex.z * cos_angle;
  vertex.y = new_y;
  vertex.z = new_z;
}

void RotateStrategy::rotateY(Vertex_3d& vertex, double sin_angle,
                             double cos_angle) {
  double new_x = vertex.x * cos_angle - vertex.z * sin_angle;
  double new_z = vertex.x * sin_angle + vertex.z * cos_angle;
  vertex.x = new_x;
  vertex.z = new_z;
}

void RotateStrategy::rotateZ(Vertex_3d& vertex, double sin_angle,
                             double cos_angle) {
  double new_x = vertex.x * cos_angle - vertex.y * sin_angle;
  double new_y = vertex.x * sin_angle + vertex.y * cos_angle;
  vertex.x = new_x;
  vertex.y = new_y;
}

}  // namespace s21
