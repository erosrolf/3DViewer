#include "centring_strategy.h"

#include <limits>

namespace s21 {
void CentringStrategy::modify(Obj& obj) {
  for (auto& vertex : obj.vertexes) {
    vertex.x -= obj.center.x;
    vertex.y -= obj.center.y;
    vertex.z -= obj.center.z;
  }
}
}  // namespace s21
