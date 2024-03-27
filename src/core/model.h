#ifndef _3DVIEWER_SRC_CORE_MODEL_H_
#define _3DVIEWER_SRC_CORE_MODEL_H_

#include "obj.h"
#include "obj_modifier_strategy/scale_strategy.h"
#include "obj_modifier_strategy/translation_strategy.h"
#include "obj_modifier_strategy/rotate_strategy.h"

namespace s21 {

class Model {
 public:
  Model() {}

  const Obj& openNewObj(const char* file_name) {
    obj_.clear();
    obj_.parseFile(file_name);
    return obj_;
  }

  void objMoveToRight(double value) {
    obj_.modify(new TranslationStrategy(value, 0, 0));
  }

  void objMoveToLeft(double value) {
    obj_.modify(new TranslationStrategy(-value, 0, 0));
  }

  void objMoveUp(double value) {
    obj_.modify(new TranslationStrategy(0, value, 0));
  }

  void objMoveDown(double value) {
    obj_.modify(new TranslationStrategy(0, -value, 0));
  }

  void objMoveForward(double value) {
    obj_.modify(new TranslationStrategy(0, 0, value));
  }

  void objMoveBack(double value) {
    obj_.modify(new TranslationStrategy(0, 0, -value));
  }

  void objZoom(double value) { obj_.modify(new ScalingStrategy(value)); }

  void objRotateAroundX(double value) {
    obj_.modify(new RotateStrategy(s21::RotateStrategy::Type::X, value));
  }

  void objRotateAroundY(double value) {
    obj_.modify(new RotateStrategy(s21::RotateStrategy::Type::Y, value));
  }

  void objRotateAroundZ(double value) {
    obj_.modify(new RotateStrategy(s21::RotateStrategy::Type::Z, value));
  }

  bool objIsValid() const noexcept { return obj_.valid(); }

  const std::vector<Vertex_3d>& getObjVertexes() { return obj_.vertexes; }
  const std::vector<Facet_3d>& getObjPolygons() { return obj_.polygons; }

  void reset() noexcept { obj_.clear(); }

 private:
  Obj obj_;
};
}  // namespace s21

#endif  //_3DVIEWER_SRC_CORE_MODEL_H_
