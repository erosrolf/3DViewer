#ifndef SRC_3DVIEWER_MODEL_OBJ_H_
#define SRC_3DVIEWER_MODEL_OBJ_H_

#include <stdint.h>

#include <string>
#include <vector>

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
struct Facet_3d {
  std::vector<long int> vertex_indexes;  ///< array of polygon vertex indices
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
  Obj& operator=(Obj&& other);
  ~Obj() = default;

  void parseFile(const char* file_name);

  std::vector<Vertex_3d> vertexes;  ///< all vertexes of 3d model
  std::vector<Facet_3d> polygons;   ///< all polygons of 3d model
  bool is_valid;  ///< is_valid if the .obj file was successfully read and the
                  ///< data was parsed correctly

 private:
  void parseVertex(const std::string& v_line);
  void parseFacet(const std::string& f_line);
  size_t parseFacetIndex(const std::string& token_with_index);
};

}  // namespace s21

#endif  // SRC_3DVIEWER_MODEL_OBJ_H_
