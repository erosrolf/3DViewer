#include <gtest/gtest.h>

#include "../model/obj.h"

TEST(model, read_file) {
  s21::Obj obj("obj_resurces/cube.obj");
  obj.read_file();
  std::cout << "vertexes count " << obj.vertexesCount() << '\n';
  std::cout << "facets count " << obj.facetsCount() << '\n';
}
