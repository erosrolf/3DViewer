#include "obj.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>

#include "obj_modifier_strategy/obj_modifier.h"

namespace s21 {

// Constructors ------

Obj::Obj() noexcept : vertexes(0), polygons(0), is_valid(false) {}

Obj::Obj(const char* file_name) : Obj() { parseFile(file_name); }

Obj::Obj(const Obj& other)
    : vertexes(other.vertexes),
      polygons(other.polygons),
      is_valid(other.is_valid) {}

Obj::Obj(const Obj&& other) noexcept
    : vertexes(std::move(other.vertexes)),
      polygons(std::move(other.polygons)),
      is_valid(other.is_valid) {}

void Obj::parseVertex(const std::string& v_line) {
  std::istringstream iss(v_line.substr(2));
  Vertex_3d vertex;
  if (iss >> vertex.x >> vertex.y >> vertex.z) {
    vertexes.push_back(vertex);
  } else {
    std::cerr << "Error parse vertex: " << v_line << '\n';
    is_valid = false;
  }
}

Obj& Obj::operator=(const Obj& other) {
  if (this != &other) {
    vertexes = other.vertexes;
    polygons = other.polygons;
    is_valid = other.is_valid;
  }
  return *this;
}

Obj& Obj::operator=(Obj&& other) noexcept {
  if (this != &other) {
    vertexes = std::move(other.vertexes);
    polygons = std::move(other.polygons);
    is_valid = other.is_valid;
    other.is_valid = false;
  }
  return *this;
}

// Public Metods ------

void Obj::parseFile(const char* file_name) {
  std::ifstream file(file_name);
  if (file.is_open()) {
    is_valid = true;
  } else {
    std::cerr << "Error opening file: " << file_name << '\n';
    return;
  }

  std::string line;
  while (std::getline(file, line) && is_valid) {
    if (line.rfind("v ", 0) == 0) {
      parseVertex(line);
    } else if (line.rfind("f ", 0) == 0) {
      parseFacet(line);
    }
  }
}

void Obj::modify(ObjModifier* strategy) {
  if (strategy) {
    strategy->modify(*this);
  }
}

// Private Metods ------

size_t Obj::parseFacetIndex(const std::string& token_with_index) {
  std::istringstream iss(token_with_index);
  long int num_1 = 0, num_2 = 0, num_3 = 0;
  char slash_1 = 0x00, slash_2 = 0x00;

  iss >> num_1 >> slash_1 >> num_2 >> slash_2 >> num_3;

  if (slash_1 != '/' || slash_2 != '/' ||
      num_1 > static_cast<long int>(vertexes.size())) {
    std::cerr << "Error parse facet index: " << token_with_index << '\n';
    is_valid = false;
  }
  if (num_1 < 0) {
    num_1 = vertexes.size() - num_1;
  }
  return num_1;
}

void Obj::parseFacet(const std::string& f_line) {
  std::istringstream iss(f_line.substr(2));
  Facet_3d poly;
  poly.vertex_indexes.reserve(4);
  std::string token_with_index;

  while (iss >> token_with_index && is_valid) {
    poly.vertex_indexes.push_back(parseFacetIndex(token_with_index));
  }
  if (is_valid) {
    polygons.push_back(poly);
  }
}

};  // namespace s21
