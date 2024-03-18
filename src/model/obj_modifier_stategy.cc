#include "obj_modifier_stategy.h"

#include "obj.h"

namespace s21 {

TranslationStrategy::TranslationStrategy(double x, double y, double z)
    : x_(x), y_(y), z_(z) {}

void TranslationStrategy::Modify(Obj& obj) {
  for (auto& vertex : obj.vertexes) {
    vertex.x += x_;
    vertex.y += y_;
    vertex.z += z_;
  }
}
}  // namespace s21
