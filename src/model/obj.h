#ifndef SRC_3DVIEWER_MODEL_OBJ_H_
#define SRC_3DVIEWER_MODEL_OBJ_H_

#include <stdint.h>

#include <string>
#include <vector>

namespace s21 {
using std::string;

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
  uint8_t count_of_vertexes;
  std::vector<size_t> vertex_indexes;  ///< array of polygon vertex indices
};

/**
 * @brief class Obj
 * reads a file in .obj format and writes data about the 3d model
 */
class Obj {
 public:
  using Vertex_3d = struct Vertex_3d;
  using Facet_3d = struct Facet_3d;

  Obj();
  Obj(const char* file_name);
  size_t vertexesCount() { return count_of_vertexes_; }
  size_t facetsCount() { return count_of_faces_; }

 private:
  void readFile();
  void parseVertex(const std::string& v_line);
  void parseFacet(const std::string& f_line);
  size_t parseFacetIndex(const string& token_with_index);

  size_t count_of_vertexes_;
  size_t count_of_faces_;
  double max_coordinate_;  ///< the most distant coordinate from the center
  std::vector<Vertex_3d> vertexes_;  ///< all vertexes of 3d model into vector
  std::vector<Facet_3d> polygons_;   ///< all polygons of 3d model into stack
  bool is_valid_;

  std::string file_name_;
};

}  // namespace s21

#endif  // SRC_3DVIEWER_MODEL_OBJ_H_
