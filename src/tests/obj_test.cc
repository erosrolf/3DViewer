#include "../core/obj.h"

#include <gtest/gtest.h>

TEST(obj, parse_file) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  s21::Obj obj2("tests/obj_resurces/cube.obj");

  std::vector<s21::Vertex_3d> ref = {
      {1.000000, 1.000000, -1.000000},  {1.000000, -1.000000, -1.000000},
      {1.000000, 1.000000, 1.000000},   {1.000000, -1.000000, 1.000000},
      {-1.000000, 1.000000, -1.000000}, {-1.000000, -1.000000, -1.000000},
      {-1.000000, 1.000000, 1.000000},  {-1.000000, -1.000000, 1.000000}};

  ASSERT_TRUE(obj.is_valid);
  ASSERT_EQ(obj.vertexes, ref);
  ASSERT_EQ(obj, obj2);
  ASSERT_EQ(obj, obj);
}
