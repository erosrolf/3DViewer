#include <gtest/gtest.h>

#include <iostream>

#include "../core/obj.h"
#include "../core/obj_modifier_strategy/obj_modifier_strategy.h"

TEST(obj_translation, x_translation) {
  s21::Obj obj("obj_resurces/cube.obj");
  s21::TranslationStrategy moveLeft(-1, 0, 0);
  obj.modify(&moveLeft);

  std::vector<s21::Vertex_3d> ref = {{0.0, 1.0, -1.0},  {0.0, -1.0, -1.0},
                                     {0.0, 1.0, 1.0},   {0.0, -1.0, 1.0},
                                     {-2.0, 1.0, -1.0}, {-2.0, -1.0, -1.0},
                                     {-2.0, 1.0, 1.0},  {-2.0, -1.0, 1.0}};

  auto ref_vertex = ref.begin();
  for (auto vertex : obj.vertexes) {
    ASSERT_EQ(vertex.x, ref_vertex->x);
    ASSERT_EQ(vertex.y, ref_vertex->y);
    ASSERT_EQ(vertex.z, ref_vertex->z);
    ++ref_vertex;
  }
}
