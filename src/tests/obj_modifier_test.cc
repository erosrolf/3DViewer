#include <gtest/gtest.h>

#include <iostream>

#include "../core/obj.h"
#include "../core/obj_modifier_strategy/obj_modifier_strategy.h"
#include "../core/obj_modifier_strategy/rotate_strategy.h"
#include "../core/obj_modifier_strategy/translation_strategy.h"

TEST(obj_translation, x_translation) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  s21::TranslationStrategy moveLeft(-1, 0, 0);
  obj.modify(&moveLeft);
  std::vector<s21::Vertex_3d> ref = {{0.0, 1.0, -1.0},  {0.0, -1.0, -1.0},
                                     {0.0, 1.0, 1.0},   {0.0, -1.0, 1.0},
                                     {-2.0, 1.0, -1.0}, {-2.0, -1.0, -1.0},
                                     {-2.0, 1.0, 1.0},  {-2.0, -1.0, 1.0}};
  ASSERT_EQ(ref, obj.vertexes);
}

TEST(obj_translation, x_rotation_on_5_degrees_pos) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  s21::RotateStrategy rotate(s21::RotateStrategy::Type::X, 5);
  obj.modify(&rotate);
  std::vector<s21::Vertex_3d> ref = {
      {1.0, 1.08335, -0.909039},  {1.0, -0.909039, -1.08335},
      {1.0, 0.909039, 1.08335},   {1.0, -1.08335, 0.909039},
      {-1.0, 1.08335, -0.909039}, {-1.0, -0.909039, -1.08335},
      {-1.0, 0.909039, 1.08335},  {-1.0, -1.08335, 0.909039}};
  ASSERT_EQ(ref, obj.vertexes);
}

TEST(obj_translation, x_rotation_on_45_degrees_pos) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  s21::RotateStrategy rotate(s21::RotateStrategy::Type::X, 45);
  obj.modify(&rotate);
  std::vector<s21::Vertex_3d> ref = {
      {1.000000, 1.414213, 0.000000},  {1.000000, -0.000000, -1.414213},
      {1.000000, 0.000000, 1.414213},  {1.000000, -1.414213, 0.000000},
      {-1.000000, 1.414213, 0.000000}, {-1.000000, -0.000000, -1.414213},
      {-1.000000, 0.000000, 1.414213}, {-1.000000, -1.414213, 0.000000}};
  ASSERT_EQ(ref, obj.vertexes);
}

TEST(obj_translation, x_rotation_on_5_degrees_neg) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  s21::RotateStrategy rotate(s21::RotateStrategy::Type::X, -5);
  obj.modify(&rotate);
  std::vector<s21::Vertex_3d> ref = {
      {1, 0.909039, -1.08335},  {1, -1.08335, -0.909039},
      {1, 1.08335, 0.909039},   {1, -0.909039, 1.08335},
      {-1, 0.909039, -1.08335}, {-1, -1.08335, -0.909039},
      {-1, 1.08335, 0.909039},  {-1, -0.909039, 1.08335}};
  ASSERT_EQ(ref, obj.vertexes);
}

TEST(obj_translation, y_rotation_on_5_degrees_pos) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  s21::RotateStrategy rotate(s21::RotateStrategy::Type::Y, 5);
  obj.modify(&rotate);
  std::vector<s21::Vertex_3d> ref = {
      {1.08335, 1, -0.909039},  {1.08335, -1, -0.909039},
      {0.909039, 1, 1.08335},   {0.909039, -1, 1.08335},
      {-0.909039, 1, -1.08335}, {-0.909039, -1, -1.08335},
      {-1.08335, 1, 0.909039},  {-1.08335, -1, 0.909039}};
  ASSERT_EQ(ref, obj.vertexes);
}

TEST(obj_translation, y_rotation_on_5_degrees_neg) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  s21::RotateStrategy rotate(s21::RotateStrategy::Type::Y, -5);
  obj.modify(&rotate);
  std::vector<s21::Vertex_3d> ref = {
      {0.909039, 1, -1.08335},  {0.909039, -1, -1.08335},
      {1.08335, 1, 0.909039},   {1.08335, -1, 0.909039},
      {-1.08335, 1, -0.909039}, {-1.08335, -1, -0.909039},
      {-0.909039, 1, 1.08335},  {-0.909039, -1, 1.08335}};
  ASSERT_EQ(ref, obj.vertexes);
}

TEST(obj_translation, z_rotation_on_5_degrees_pos) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  s21::RotateStrategy rotate(s21::RotateStrategy::Type::Z, 5);
  obj.modify(&rotate);
  std::vector<s21::Vertex_3d> ref = {
      {0.909039, 1.08335, -1},  {1.08335, -0.909039, -1},
      {0.909039, 1.08335, 1},   {1.08335, -0.909039, 1},
      {-1.08335, 0.909039, -1}, {-0.909039, -1.08335, -1},
      {-1.08335, 0.909039, 1},  {-0.909039, -1.08335, 1}};
  ASSERT_EQ(ref, obj.vertexes);
}

TEST(obj_translation, z_rotation_on_5_degrees_neg) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  s21::RotateStrategy rotate(s21::RotateStrategy::Type::Z, -5);
  obj.modify(&rotate);
  std::vector<s21::Vertex_3d> ref = {
      {1.08335, 0.909039, -1},  {0.909039, -1.08335, -1},
      {1.08335, 0.909039, 1},   {0.909039, -1.08335, 1},
      {-0.909039, 1.08335, -1}, {-1.08335, -0.909039, -1},
      {-0.909039, 1.08335, 1},  {-1.08335, -0.909039, 1}};
  ASSERT_EQ(ref, obj.vertexes);
}

TEST(obj_translation, xyz_rotation_on_0_degrees) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  std::vector<s21::Vertex_3d> ref = {
      {1.000000, 1.000000, -1.000000},  {1.000000, -1.000000, -1.000000},
      {1.000000, 1.000000, 1.000000},   {1.000000, -1.000000, 1.000000},
      {-1.000000, 1.000000, -1.000000}, {-1.000000, -1.000000, -1.000000},
      {-1.000000, 1.000000, 1.000000},  {-1.000000, -1.000000, 1.000000}};
  s21::RotateStrategy rotate_x(s21::RotateStrategy::Type::Z, 0);
  s21::RotateStrategy rotate_y(s21::RotateStrategy::Type::Z, 0);
  s21::RotateStrategy rotate_z(s21::RotateStrategy::Type::Z, 0);
  obj.modify(&rotate_x);
  ASSERT_EQ(ref, obj.vertexes);
  obj.modify(&rotate_y);
  ASSERT_EQ(ref, obj.vertexes);
  obj.modify(&rotate_z);
  ASSERT_EQ(ref, obj.vertexes);
}

TEST(obj_scale, zoom_in_10_percent) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  s21::ScalingStrategy zoomIn(1.1);
  obj.modify(&zoomIn);
  std::vector<s21::Vertex_3d> ref = {{1.1, 1.1, -1.1},  {1.1, -1.1, -1.1},
                                     {1.1, 1.1, 1.1},   {1.1, -1.1, 1.1},
                                     {-1.1, 1.1, -1.1}, {-1.1, -1.1, -1.1},
                                     {-1.1, 1.1, 1.1},  {-1.1, -1.1, 1.1}};
  ASSERT_EQ(ref, obj.vertexes);
}

TEST(obj_scale, zoom_out_10_percent) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  s21::ScalingStrategy zoomOut(0.9);
  obj.modify(&zoomOut);
  std::vector<s21::Vertex_3d> ref = {{0.9, 0.9, -0.9},  {0.9, -0.9, -0.9},
                                     {0.9, 0.9, 0.9},   {0.9, -0.9, 0.9},
                                     {-0.9, 0.9, -0.9}, {-0.9, -0.9, -0.9},
                                     {-0.9, 0.9, 0.9},  {-0.9, -0.9, 0.9}};
  ASSERT_EQ(ref, obj.vertexes);
}
