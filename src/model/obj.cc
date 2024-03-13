#include "obj.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>

namespace s21 {
Obj::Obj(const char* file_name)
    : count_of_vertexes_(0),
      count_of_faces_(0),
      max_coordinate_(0),
      vertexes_(),
      polygons_(),
      is_valid_(true),
      file_name_(file_name) {}

void Obj::parseVertex(const string& v_line) {
  std::istringstream iss(v_line);
  Vertex_3d vertex;
  string prefix;
  if (iss >> prefix >> vertex.x >> vertex.y >> vertex.z && prefix == "v") {
    ++count_of_vertexes_;
    vertexes_.push_back(vertex);
    std::cout << v_line << '\n';
  }
}

size_t Obj::parseFacetIndex(const string& token_with_index) {
  std::istringstream iss(token_with_index);
  string part;
  size_t number;
  size_t index_of_vertex;
  int count = 3;

  while (std::getline(iss, part, '/') && is_valid_) {
    std::istringstream partStream(part);
    if (partStream >> number) {
      if (count == 3) {
        index_of_vertex = number;
      }
      --count;
    } else {
      is_valid_ = false;
    }
  }
  if (count) {
    is_valid_ = false;
  }
  return index_of_vertex;
}

void Obj::parseFacet(const string& f_line) {
  std::istringstream iss(f_line);
  Facet_3d poly;
  poly.vertex_indexes.reserve(3);
  string token;
  if (iss >> token && token == "f") {
    std::cout << f_line << '\n';
    while (iss >> token && is_valid_) {
      ++poly.count_of_vertexes;
      poly.vertex_indexes.push_back(parseFacetIndex(token));
    }
  }
  if (is_valid_) {
    ++count_of_faces_;
    polygons_.push(poly);
  }
}

void Obj::read_file() {
  std::ifstream file(file_name_);
  if (!file.is_open()) {
    is_valid_ = false;
    std::cerr << "Error opening file: " << file_name_ << '\n';
    return;
  }

  string line;
  while (std::getline(file, line) && is_valid_) {
    if (line.front() == 'v') {
      parseVertex(line);
    } else if (line.front() == 'f') {
      parseFacet(line);
    }
  }
}

};  // namespace s21
