#include "scale_strategy.h"

#include "../obj.h"

namespace s21 {

void ScalingStrategy::modify(Obj& obj) {
  for (auto& vertex : obj.vertexes) {
    vertex.x *= s_;
    vertex.y *= s_;
    vertex.z *= s_;
  }
  obj.center.x *= s_;
  obj.center.y *= s_;
  obj.center.z *= s_;
}

}  // namespace s21
