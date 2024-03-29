#ifndef SRC_3DVIEWER_MODEL_OBJ_H_
#define SRC_3DVIEWER_MODEL_OBJ_H_

#include <stdint.h>

#include <algorithm>
#include <cmath>
#include <memory>
#include <string>
#include <vector>

namespace s21 {
class ObjModifier;

/**
 * @brief struct Vertex_3d
 * contains the coordinates of a point in 3d space.
 */
struct Vertex_3d {
  bool operator==(const Vertex_3d& other) const;

  double x, y, z;
};

/**
 * @brief struct Polygon_3d
 * contains information about the 3d model polygon
 */
struct Facet_3d {
  bool operator==(const Facet_3d& other) const {
    return vertex_indexes == other.vertex_indexes;
  }

  std::vector<long> vertex_indexes;  ///< array of polygon vertex indices
};

/**
 * @brief class ExtremePositions
 * stores extreme values of the model while parsing obj from file
 */
struct ExtremePositions {
  ExtremePositions()
      : empty(true),
        min_x(0.0),
        min_y(0.0),
        min_z(0.0),
        max_x(0.0),
        max_y(0.0),
        max_z(0.0) {}

  void reset() { empty = true; }
  void update(Vertex_3d v);
  double getMaxValue();
  Vertex_3d getCenterPoint();

  bool empty;
  double min_x, min_y, min_z;
  double max_x, max_y, max_z;
};

/**
 * @brief class Obj
 * reads a file in .obj format and writes data about the 3d model
 */
class Obj {
 public:
  Obj() noexcept;
  Obj(const char* file_name);
  Obj(const Obj& other);
  Obj(const Obj&& other) noexcept;
  Obj& operator=(const Obj& other);
  Obj& operator=(Obj&& other) noexcept;
  ~Obj() = default;

  void parseFile(const char* file_name);
  void modify(std::unique_ptr<ObjModifier> strategy);
  bool operator==(const Obj& other) const;
  bool valid() const noexcept { return is_valid_; }
  void clear() noexcept;
  Vertex_3d findCenter();

  double max_value;                 ///< value with the maximum coordinate
  Vertex_3d center;                 ///< obj with obj center coordinates
  std::vector<Vertex_3d> vertexes;  ///< all vertexes of 3d model
  std::vector<Facet_3d> polygons;   ///< all polygons of 3d model

 private:
  void parseVertex(const std::string& v_line, ExtremePositions& extreme_pos);
  void parseFacet(const std::string& f_line);
  size_t parseFacetIndex(const std::string& token_with_index,
                         const std::string& f_line);

  bool is_valid_;
};

}  // namespace s21

#endif  // SRC_3DVIEWER_MODEL_OBJ_H_
