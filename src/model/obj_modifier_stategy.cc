#include "obj_modifier_stategy.h"

#include "obj.h"

namespace s21 {

void RotateStrategy::Modify(Obj& obj) {
  for (auto& vertex : obj.vertexes) {
  }
}

void ScalingStrategy::Modify(Obj& obj) {
  for (auto& vertex : obj.vertexes) {
    vertex.x *= s_;
    vertex.y *= s_;
    vertex.z *= s_;
  }
}

void TranslationStrategy::Modify(Obj& obj) {
  for (auto& vertex : obj.vertexes) {
    vertex.x += x_;
    vertex.y += y_;
    vertex.z += z_;
  }
}

}  // namespace s21
