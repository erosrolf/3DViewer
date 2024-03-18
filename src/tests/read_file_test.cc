#include <gtest/gtest.h>

#include "../model/obj.h"

TEST(model, read_file) {
  s21::Obj obj("obj_resurces/cube.obj");

  for (auto it : obj.vertexes) {
    std::cout << it.x << ' ' << it.y << ' ' << it.z << '\n';
  }

  for (auto it : obj.polygons) {
    for (auto it_2 : it.vertex_indexes) {
      std::cout << it_2 << ' ';
    }
    std::cout << '\n';
  }

  std::cout << "vertexes count " << obj.vertexes.size() << '\n';
  std::cout << "facets count " << obj.polygons.size() << '\n';
  std::cout << "is_valid " << obj.is_valid << '\n';
}
