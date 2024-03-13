#ifndef SRC_3DVIEWER_MODEL_OBJ_H_
#define SRC_3DVIEWER_MODEL_OBJ_H_

#include <cstddef>
#include <deque>
#include <stack>

namespace s21 {

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
struct Polygon_3d {
  uint8_t count_of_vertexes;
  std::deque<size_t> vertex_indexes;  ///< array of polygon vertex indices
};

/**
 * @brief class Obj
 * reads a file in .obj format and writes data about the 3d model
 */
class Obj {
 public:
  using Vertex_3d = struct Vertex_3d;
  using Polygon_3d = struct Polygon_3d;

 private:
  size_t count_of_vertexes_;
  size_t count_of_faces_;
  double max_coordinate_;  ///< the most distant coordinate from the center
  std::deque<Vertex_3d> vertexes_;   ///< all vertexes of 3d model into vector
  std::stack<Polygon_3d> polygons_;  ///< all polygons of 3d model into stack
};

}  // namespace s21

#endif  // SRC_3DVIEWER_MODEL_OBJ_H_
