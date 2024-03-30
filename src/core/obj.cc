#include "obj.h"

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>

#include "obj_modifier_strategy/obj_modifier.h"

namespace s21 {

bool Vertex_3d::operator==(const Vertex_3d& other) const {
  const double epsilon = 1e-6;
  return std::fabs(x - other.x) < epsilon && std::fabs(y - other.y) < epsilon &&
         std::fabs(z - other.z) < epsilon;
}

void ExtremePositions::update(Vertex_3d v) {
  if (empty) {
    empty = false;
    min_x = max_x = v.x;
    min_y = max_y = v.y;
    min_z = max_z = v.z;
  } else {
    if (v.x < min_x) {
      min_x = v.x;
    }
    if (v.y < min_y) {
      min_y = v.y;
    }
    if (v.z < min_z) {
      min_z = v.z;
    }
    if (v.x > max_x) {
      max_x = v.x;
    }
    if (v.y > max_y) {
      max_y = v.y;
    }
    if (v.z > max_z) {
      max_z = v.z;
    }
  }
}

double ExtremePositions::getMaxValue() {
  double max_val = std::abs(min_x);
  max_val = std::max(max_val, std::abs(min_y));
  max_val = std::max(max_val, std::abs(min_z));
  max_val = std::max(max_val, std::abs(max_x));
  max_val = std::max(max_val, std::abs(max_y));
  max_val = std::max(max_val, std::abs(max_z));
  return max_val;
}

Vertex_3d ExtremePositions::getCenterPoint() {
  return Vertex_3d{(min_x + max_x) / 2, (min_y + max_y) / 2,
                   (min_z + max_z) / 2};
}

//  OBJ Constructors ------

Obj::Obj() noexcept
    : max_value(0.0),
      center({0, 0, 0}),
      vertexes(0),
      polygons(0),
      is_valid_(false) {}

Obj::Obj(const char* file_name) : Obj() { parseFile(file_name); }

Obj::Obj(const Obj& other)
    : max_value(other.max_value),
      center(other.center),
      vertexes(other.vertexes),
      polygons(other.polygons),
      is_valid_(other.is_valid_) {}

Obj::Obj(const Obj&& other) noexcept
    : max_value(std::move(other.max_value)),
      center(std::move(other.center)),
      vertexes(std::move(other.vertexes)),
      polygons(std::move(other.polygons)),
      is_valid_(other.is_valid_) {
  this->clear();
}

Obj& Obj::operator=(const Obj& other) {
  if (this != &other) {
    max_value = other.max_value;
    center = other.center;
    vertexes = other.vertexes;
    polygons = other.polygons;
    is_valid_ = other.is_valid_;
  }
  return *this;
}

Obj& Obj::operator=(Obj&& other) noexcept {
  if (this != &other) {
    max_value = std::move(other.max_value);
    center = std::move(other.center);
    vertexes = std::move(other.vertexes);
    polygons = std::move(other.polygons);
    is_valid_ = other.is_valid_;
    other.is_valid_ = false;
    this->clear();
  }
  return *this;
}

// OBJ Public Metods ------
void Obj::parseFile(const char* file_name) {
  std::ifstream file(file_name);
  if (file.is_open()) {
    is_valid_ = true;
  } else {
    std::cerr << "Error opening file: " << file_name << '\n';
    return;
  }

  ExtremePositions min_max;
  std::string line;
  while (std::getline(file, line) && is_valid_) {
    if (line.rfind("v ", 0) == 0) {
      parseVertex(line, min_max);
    } else if (line.rfind("f ", 0) == 0) {
      parseFacet(line);
    }
  }
  center = min_max.getCenterPoint();
  max_value = min_max.getMaxValue();
}

void Obj::modify(std::unique_ptr<ObjModifier> strategy) {
  if (strategy) {
    strategy->modify(*this);
  }
}

bool Obj::operator==(const Obj& other) const {
  if (this == &other) {
    return true;
  }
  return is_valid_ == other.is_valid_ && vertexes == other.vertexes &&
         polygons == other.polygons;
}

void Obj::clear() noexcept {
  max_value = 0.0;
  center = {0, 0, 0};
  vertexes.clear();
  polygons.clear();
  is_valid_ = true;
}

// OBJ Private Metods ------

void Obj::parseVertex(const std::string& v_line, ExtremePositions& min_max) {
  std::istringstream iss(v_line.substr(2));
  Vertex_3d vertex;
  if (iss >> vertex.x >> vertex.y >> vertex.z) {
    vertexes.push_back(vertex);
    min_max.update(vertex);
  } else {
    std::cerr << "Error parse vertex in line: " << v_line << '\n';
    is_valid_ = false;
  }
}

void Obj::parseFacet(const std::string& f_line) {
  std::istringstream iss(f_line.substr(2));
  Facet_3d poly;
  poly.vertex_indexes.reserve(4);
  std::string token_with_index;

  while (iss >> token_with_index && is_valid_) {
    poly.vertex_indexes.push_back(parseFacetIndex(token_with_index, f_line));
  }
  if (is_valid_) {
    polygons.push_back(poly);
  }
}

size_t Obj::parseFacetIndex(const std::string& token_with_index,
                            const std::string& f_line) {
  std::istringstream iss(token_with_index);
  long int num_1 = 0;

  iss >> num_1;

  if (iss.fail() || num_1 > (long)vertexes.size() ||
      (num_1 < 0 && (-1 * num_1) > (long)vertexes.size())) {
    std::cerr << "Error parse facet in line: " << f_line;
    is_valid_ = false;
  } else if (num_1 < 0) {
    num_1 = vertexes.size() + (num_1 + 1);
  }
  return num_1 - 1;
}

};  // namespace s21
