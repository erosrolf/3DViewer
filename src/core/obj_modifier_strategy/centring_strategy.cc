#include "centring_strategy.h"

#include <limits>

namespace s21 {
void CentringStrategy::modify(Obj& obj) {
  double min_x = obj.vertexes.front().x;
  double max_x = min_x;
  double min_y = obj.vertexes.front().y;
  double max_y = min_y;
  double min_z = obj.vertexes.front().z;
  double max_z = min_z;

  for (const auto& vertex : obj.vertexes) {
    min_x = std::min(min_x, vertex.x);
    max_x = std::max(max_x, vertex.x);
    min_y = std::min(min_y, vertex.y);
    max_y = std::max(max_y, vertex.y);
    min_z = std::min(min_z, vertex.z);
    max_z = std::max(max_z, vertex.z);
  }

  double offset_x = (min_x + max_x) / 2.0;
  double offset_y = (min_y + max_y) / 2.0;
  double offset_z = (min_z + max_z) / 2.0;

  for (auto& vertex : obj.vertexes) {
    vertex.x -= offset_x;
    vertex.y -= offset_y;
    vertex.z -= offset_z;
  }
}
}  // namespace s21
