#include "../core/obj.h"

#include <gtest/gtest.h>

TEST(obj, open_cube) {
  s21::Obj obj("tests/obj_resurces/cube.obj");

  s21::Vertex_3d ref_center({0, 0, 0});
  std::vector<s21::Vertex_3d> ref = {
      {1.000000, 1.000000, -1.000000},  {1.000000, -1.000000, -1.000000},
      {1.000000, 1.000000, 1.000000},   {1.000000, -1.000000, 1.000000},
      {-1.000000, 1.000000, -1.000000}, {-1.000000, -1.000000, -1.000000},
      {-1.000000, 1.000000, 1.000000},  {-1.000000, -1.000000, 1.000000}};
  std::vector<s21::Facet_3d> ref_facets = {
      s21::Facet_3d{{0, 4, 6, 2}}, s21::Facet_3d{{3, 2, 6, 7}},
      s21::Facet_3d{{7, 6, 4, 5}}, s21::Facet_3d{{5, 1, 3, 7}},
      s21::Facet_3d{{1, 0, 2, 3}}, s21::Facet_3d{{5, 4, 0, 1}}};

  ASSERT_TRUE(obj.valid());
  ASSERT_EQ(obj.vertexes, ref);
  ASSERT_EQ(obj.polygons, ref_facets);
  ASSERT_EQ(obj.center, ref_center);
  ASSERT_EQ(obj.max_value, 1.0);
}

TEST(obj, open_neg_cube) {
  s21::Obj obj("tests/obj_resurces/neg_cube.obj");

  s21::Vertex_3d ref_center({0, 0, 0});
  std::vector<s21::Vertex_3d> ref = {
      {1.000000, 1.000000, -1.000000},  {1.000000, -1.000000, -1.000000},
      {1.000000, 1.000000, 1.000000},   {1.000000, -1.000000, 1.000000},
      {-1.000000, 1.000000, -1.000000}, {-1.000000, -1.000000, -1.000000},
      {-1.000000, 1.000000, 1.000000},  {-1.000000, -1.000000, 1.000000}};
  std::vector<s21::Facet_3d> ref_facets = {
      s21::Facet_3d{{0, 4, 6, 2}}, s21::Facet_3d{{3, 2, 6, 7}},
      s21::Facet_3d{{7, 6, 4, 5}}, s21::Facet_3d{{5, 1, 3, 7}},
      s21::Facet_3d{{1, 0, 2, 3}}, s21::Facet_3d{{5, 4, 0, 1}}};

  ASSERT_TRUE(obj.valid());
  ASSERT_EQ(obj.vertexes, ref);
  ASSERT_EQ(obj.polygons, ref_facets);
  ASSERT_EQ(obj.center, ref_center);
  ASSERT_EQ(obj.max_value, 1.0);
}

TEST(obj, test_operatror_eq) {
  s21::Obj obj1("tests/obj_resurces/cube.obj");
  s21::Obj obj2("tests/obj_resurces/cube.obj");
  ASSERT_EQ(obj1, obj2);
  ASSERT_EQ(obj1, obj1);
}

TEST(obj, constructor_copy) {
  s21::Obj obj1("tests/obj_resurces/cube.obj");
  s21::Obj obj2(obj1);
  ASSERT_EQ(obj1, obj2);
}

TEST(obj, constructor_move) {
  // s21::Obj* obj1 = new s21::Obj("tests/obj_resurces/cube.obj");
  // s21::Obj obj2 = (std::move(*obj1));
  // ASSERT_EQ(*obj1, obj2);
  s21::Obj obj1("tests/obj_resurces/cube.obj");
  s21::Obj obj2(std::move(obj1));
}

TEST(obj, constructor_equals_copy) {
  s21::Obj obj1("tests/obj_resurces/cube.obj");
  s21::Obj obj2;
  obj2 = obj1;
  ASSERT_EQ(obj1, obj2);
}

TEST(obj, constructor_equals_move) {
  s21::Obj obj1("tests/obj_resurces/cube.obj");
  s21::Obj obj2;
  obj2 = std::move(obj1);
}
