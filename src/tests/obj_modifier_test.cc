#include <gtest/gtest.h>

#include <iostream>

#include "../core/obj.h"
#include "../core/obj_modifier_strategy/centring_strategy.h"
#include "../core/obj_modifier_strategy/obj_modifier_strategy.h"
#include "../core/obj_modifier_strategy/rotate_strategy.h"
#include "../core/obj_modifier_strategy/translation_strategy.h"

TEST(obj_translation, x_translation) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  obj.modify(std::make_unique<s21::TranslationStrategy>(-1, 0, 0));
  std::vector<s21::Vertex_3d> ref = {{0.0, 1.0, -1.0},  {0.0, -1.0, -1.0},
                                     {0.0, 1.0, 1.0},   {0.0, -1.0, 1.0},
                                     {-2.0, 1.0, -1.0}, {-2.0, -1.0, -1.0},
                                     {-2.0, 1.0, 1.0},  {-2.0, -1.0, 1.0}};
  ASSERT_EQ(ref, obj.vertexes);
}

TEST(obj_translation, x_rotation_on_5_degrees_pos) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  obj.modify(
      std::make_unique<s21::RotateStrategy>(s21::RotateStrategy::Type::X, 5));
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
  obj.modify(
      std::make_unique<s21::RotateStrategy>(s21::RotateStrategy::Type::X, 45));
  std::vector<s21::Vertex_3d> ref = {
      {1.000000, 1.414213, 0.000000},  {1.000000, -0.000000, -1.414213},
      {1.000000, 0.000000, 1.414213},  {1.000000, -1.414213, 0.000000},
      {-1.000000, 1.414213, 0.000000}, {-1.000000, -0.000000, -1.414213},
      {-1.000000, 0.000000, 1.414213}, {-1.000000, -1.414213, 0.000000}};
  ASSERT_EQ(ref, obj.vertexes);
}

TEST(obj_translation, x_rotation_on_5_degrees_neg) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  obj.modify(
      std::make_unique<s21::RotateStrategy>(s21::RotateStrategy::Type::X, -5));
  std::vector<s21::Vertex_3d> ref = {
      {1, 0.909039, -1.08335},  {1, -1.08335, -0.909039},
      {1, 1.08335, 0.909039},   {1, -0.909039, 1.08335},
      {-1, 0.909039, -1.08335}, {-1, -1.08335, -0.909039},
      {-1, 1.08335, 0.909039},  {-1, -0.909039, 1.08335}};
  ASSERT_EQ(ref, obj.vertexes);
}

TEST(obj_translation, y_rotation_on_5_degrees_pos) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  obj.modify(
      std::make_unique<s21::RotateStrategy>(s21::RotateStrategy::Type::Y, 5));
  std::vector<s21::Vertex_3d> ref = {
      {1.08335, 1, -0.909039},  {1.08335, -1, -0.909039},
      {0.909039, 1, 1.08335},   {0.909039, -1, 1.08335},
      {-0.909039, 1, -1.08335}, {-0.909039, -1, -1.08335},
      {-1.08335, 1, 0.909039},  {-1.08335, -1, 0.909039}};
  ASSERT_EQ(ref, obj.vertexes);
}

TEST(obj_translation, y_rotation_on_5_degrees_neg) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  obj.modify(
      std::make_unique<s21::RotateStrategy>(s21::RotateStrategy::Type::Y, -5));
  std::vector<s21::Vertex_3d> ref = {
      {0.909039, 1, -1.08335},  {0.909039, -1, -1.08335},
      {1.08335, 1, 0.909039},   {1.08335, -1, 0.909039},
      {-1.08335, 1, -0.909039}, {-1.08335, -1, -0.909039},
      {-0.909039, 1, 1.08335},  {-0.909039, -1, 1.08335}};
  ASSERT_EQ(ref, obj.vertexes);
}

TEST(obj_translation, z_rotation_on_5_degrees_pos) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  obj.modify(
      std::make_unique<s21::RotateStrategy>(s21::RotateStrategy::Type::Z, 5));
  std::vector<s21::Vertex_3d> ref = {
      {0.909039, 1.08335, -1},  {1.08335, -0.909039, -1},
      {0.909039, 1.08335, 1},   {1.08335, -0.909039, 1},
      {-1.08335, 0.909039, -1}, {-0.909039, -1.08335, -1},
      {-1.08335, 0.909039, 1},  {-0.909039, -1.08335, 1}};
  ASSERT_EQ(ref, obj.vertexes);
}

TEST(obj_translation, z_rotation_on_5_degrees_neg) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  obj.modify(
      std::make_unique<s21::RotateStrategy>(s21::RotateStrategy::Type::Z, -5));
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
  obj.modify(
      std::make_unique<s21::RotateStrategy>(s21::RotateStrategy::Type::X, 0));
  ASSERT_EQ(ref, obj.vertexes);
  obj.modify(
      std::make_unique<s21::RotateStrategy>(s21::RotateStrategy::Type::Y, 0));
  ASSERT_EQ(ref, obj.vertexes);
  obj.modify(
      std::make_unique<s21::RotateStrategy>(s21::RotateStrategy::Type::Z, 0));
  ASSERT_EQ(ref, obj.vertexes);
}

TEST(obj_translation, zoom_in_10_percent) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  obj.modify(std::make_unique<s21::ScalingStrategy>(1.1));
  std::vector<s21::Vertex_3d> ref = {{1.1, 1.1, -1.1},  {1.1, -1.1, -1.1},
                                     {1.1, 1.1, 1.1},   {1.1, -1.1, 1.1},
                                     {-1.1, 1.1, -1.1}, {-1.1, -1.1, -1.1},
                                     {-1.1, 1.1, 1.1},  {-1.1, -1.1, 1.1}};
  ASSERT_EQ(ref, obj.vertexes);
}

TEST(obj_translation, zoom_out_10_percent) {
  s21::Obj obj("tests/obj_resurces/cube.obj");
  obj.modify(std::make_unique<s21::ScalingStrategy>(0.9));
  std::vector<s21::Vertex_3d> ref = {{0.9, 0.9, -0.9},  {0.9, -0.9, -0.9},
                                     {0.9, 0.9, 0.9},   {0.9, -0.9, 0.9},
                                     {-0.9, 0.9, -0.9}, {-0.9, -0.9, -0.9},
                                     {-0.9, 0.9, 0.9},  {-0.9, -0.9, 0.9}};
  ASSERT_EQ(ref, obj.vertexes);
}

TEST(obj_translation, centring) {
  s21::Obj obj("tests/obj_resurces/non_central_cube.obj");
  obj.modify(std::make_unique<s21::CentringStrategy>());
  std::vector<s21::Vertex_3d> ref = {{1.0, 1.0, -1.0},  {1.0, -1.0, -1.0},
                                     {1.0, 1.0, 1.0},   {1.0, -1.0, 1.0},
                                     {-1.0, 1.0, -1.0}, {-1.0, -1.0, -1.0},
                                     {-1.0, 1.0, 1.0},  {-1.0, -1.0, 1.0}};
  ASSERT_EQ(ref, obj.vertexes);
}