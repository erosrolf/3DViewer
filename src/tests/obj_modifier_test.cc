#include <gtest/gtest.h>

#include "../model/obj.h"
#include "../model/obj_modifier_stategy.h"

TEST(obj_translation, x_translation) {
  s21::Obj obj("obj_resurces/cube.obj");

  for (auto it : obj.vertexes) {
    std::cout << it.x << ' ' << it.y << ' ' << it.z << '\n';
  }

  s21::TranslationStrategy moveLeft(-1, 0, 0);

  obj.modify(&moveLeft);

  for (auto it : obj.vertexes) {
    std::cout << it.x << ' ' << it.y << ' ' << it.z << '\n';
  }
}
