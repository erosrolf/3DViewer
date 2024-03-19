#include "translation_strategy.h"

#include <cmath>

#include "../obj.h"

namespace s21 {

void TranslationStrategy::modify(Obj& obj) {
  for (auto& vertex : obj.vertexes) {
    vertex.x += x_;
    vertex.y += y_;
    vertex.z += z_;
  }
}

}  // namespace s21
