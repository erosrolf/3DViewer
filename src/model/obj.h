#ifndef SRC_3DVIEWER_MODEL_OBJ_H_
#define SRC_3DVIEWER_MODEL_OBJ_H_

#include <stdint.h>

#include <string>
#include <vector>

namespace s21 {
using std::string;
using std::vector;

/**
 * @brief struct Vertex_3d
 * contains the coordinates of a point in 3d space.
 */
struct Vertex_3d {
  double x, y, z;
};

/**
 * @brief struct Polygon_3d
 * contains information about the 3d model polygon
 */
struct Facet_3d {
  std::vector<size_t> vertex_indexes;  ///< array of polygon vertex indices
};

/**
 * @brief class Obj
 * reads a file in .obj format and writes data about the 3d model
 */
class Obj {
 public:
  Obj(const char* file_name);
  const std::vector<Vertex_3d> vertexes() { return vertexes_; }
  const std::vector<Facet_3d> polygons() { return polygons_; }
  bool isValid() noexcept { return is_valid_; }

 private:
  void readFile(const char* file_name);
  void parseVertex(const std::string& v_line);
  void parseFacet(const std::string& f_line);
  size_t parseFacetIndex(const string& token_with_index);
  std::vector<Vertex_3d> vertexes_;  ///< all vertexes of 3d model
  std::vector<Facet_3d> polygons_;   ///< all polygons of 3d model

  bool is_valid_;
};

}  // namespace s21

#endif  // SRC_3DVIEWER_MODEL_OBJ_H_
