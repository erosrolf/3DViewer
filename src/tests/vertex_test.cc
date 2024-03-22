#include <gtest/gtest.h>

#include "../core/obj.h"

TEST(Vertex_3d, operator_eq_01) {
  s21::Vertex_3d v_1 = {1, 2, 3};
  s21::Vertex_3d v_2 = {1, 2, 3};
  s21::Vertex_3d v_3 = {1, 3, 3};

  ASSERT_TRUE(v_1 == v_2);
  ASSERT_FALSE(v_1 == v_3);

  std::vector<s21::Vertex_3d> vv_1 = {{1, 2, 3}, {4, 5, 6}};
  std::vector<s21::Vertex_3d> vv_2 = {{1, 2, 3}, {4, 5, 6}};
  std::vector<s21::Vertex_3d> vv_3 = {{7, 8, 9}, {4, 5, 6}};

  ASSERT_TRUE(vv_1 == vv_2);
  ASSERT_FALSE(vv_1 == vv_3);
}

TEST(Vertex_3d, operator_eq_02) {
  s21::Vertex_3d v_1 = {1.0000009, 2, 3};
  s21::Vertex_3d v_2 = {1, 2, 3};
  s21::Vertex_3d v_3 = {1, 3, 3};

  ASSERT_TRUE(v_1 == v_2);
  ASSERT_FALSE(v_1 == v_3);

  std::vector<s21::Vertex_3d> vv_1 = {{1, 2, 3}, {4, 5, 6}};
  std::vector<s21::Vertex_3d> vv_2 = {{1, 2, 3}, {4, 5, 6}};
  std::vector<s21::Vertex_3d> vv_3 = {{7, 8, 9}, {4, 5, 6}};

  ASSERT_TRUE(vv_1 == vv_2);
  ASSERT_FALSE(vv_1 == vv_3);
}

TEST(Vertex_3d, operator_eq_03) {
  s21::Vertex_3d v_1 = {0, 0, 0};
  s21::Vertex_3d v_2 = {-1.11022e-16, -1.11022e-16, -1.11022e-16};

  ASSERT_TRUE(v_1 == v_2);

  std::vector<s21::Vertex_3d> vv_1 = {v_1, v_1};
  std::vector<s21::Vertex_3d> vv_2 = {v_2, v_2};
  ASSERT_TRUE(vv_1 == vv_2);
}
