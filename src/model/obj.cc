#include "obj.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>

namespace s21 {
Obj::Obj(const char* file_name) : vertexes_(), polygons_(), is_valid_(true) {
  readFile(file_name);
}

void Obj::parseVertex(const string& v_line) {
  std::istringstream iss(v_line.substr(2));
  Vertex_3d vertex;
  if (iss >> vertex.x >> vertex.y >> vertex.z) {
    vertexes_.push_back(vertex);
  }
}

size_t Obj::parseFacetIndex(const string& token_with_index) {
  std::istringstream iss(token_with_index);
  size_t num_1 = 0, num_2 = 0, num_3 = 0;
  char slash_1 = 0x00, slash_2 = 0x00;

  if (iss >> num_1 >> slash_1 >> num_2 >> slash_2 >> num_3) {
    if (slash_1 != '/' || slash_2 != '/') {
      is_valid_ = false;
    }
  }
  return num_1;
}

void Obj::parseFacet(const string& f_line) {
  std::istringstream iss(f_line.substr(2));
  Facet_3d poly;
  poly.vertex_indexes.reserve(4);
  string token_with_index;

  while (iss >> token_with_index && is_valid_) {
    poly.vertex_indexes.push_back(parseFacetIndex(token_with_index));
  }
  if (is_valid_) {
    polygons_.push_back(poly);
  }
}

void Obj::readFile(const char* file_name) {
  std::ifstream file(file_name);
  if (!file.is_open()) {
    is_valid_ = false;
    std::cerr << "Error opening file: " << file_name << '\n';
    return;
  }

  string line;
  while (std::getline(file, line) && is_valid_) {
    if (line.rfind("v ", 0) == 0) {
      parseVertex(line);
    } else if (line.rfind("f ", 0) == 0) {
      parseFacet(line);
    }
  }
}

};  // namespace s21
