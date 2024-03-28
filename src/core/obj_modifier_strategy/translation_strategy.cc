#include "translation_strategy.h"

#include <cmath>

#include "../obj.h"

namespace s21 {

TranslationStrategy::TranslationStrategy(double x, double y, double z)
    : x_(x), y_(y), z_(z) {}

void TranslationStrategy::modify(Obj& obj) {
  for (auto& vertex : obj.vertexes) {
    vertex.x += x_;
    vertex.y += y_;
    vertex.z += z_;
  }
  obj.center.x += x_;
  obj.center.y += y_;
  obj.center.z += z_;
}

}  // namespace s21
