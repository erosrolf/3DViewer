#ifndef _3DVIEWER_SRC_CORE_MODEL_H_
#define _3DVIEWER_SRC_CORE_MODEL_H_

#include <memory>

#include "obj.h"
#include "obj_modifier_strategy/obj_modifier_strategy.h"
#include "obj_modifier_strategy/translation_strategy.h"

namespace s21 {

/**
 * @brief class Model is facade for core lib.
 */
class Model {
 public:
  const Obj& openNewObj(const char* file_name) {
    obj_.clear();
    obj_.parseFile(file_name);
    return obj_;
  }

  void objMoveToRight(double value) {
    obj_.modify(std::make_unique<TranslationStrategy>(value, 0, 0));
  }

  void objMoveToLeft(double value) {
    obj_.modify(std::make_unique<TranslationStrategy>(-value, 0, 0));
  }

  void objMoveUp(double value) {
    obj_.modify(std::make_unique<TranslationStrategy>(0, value, 0));
  }

  void objMoveDown(double value) {
    obj_.modify(std::make_unique<TranslationStrategy>(0, -value, 0));
  }

  void objMoveForward(double value) {
    obj_.modify(std::make_unique<TranslationStrategy>(0, 0, value));
  }

  void objMoveBack(double value) {
    obj_.modify(std::make_unique<TranslationStrategy>(0, 0, -value));
  }

  void objZoom(double value) {
    obj_.modify(std::make_unique<ScalingStrategy>(value));
  }

  void objRotateAroundX(double value) {
    obj_.modify(
        std::make_unique<RotateStrategy>(s21::RotateStrategy::Type::X, value));
  }

  void objRotateAroundY(double value) {
    obj_.modify(
        std::make_unique<RotateStrategy>(s21::RotateStrategy::Type::Y, value));
  }

  void objRotateAroundZ(double value) {
    obj_.modify(
        std::make_unique<RotateStrategy>(s21::RotateStrategy::Type::Z, value));
  }

  void objCentering() {
    obj_.modify(std::make_unique<CentringStrategy>(s21::CentringStrategy()));
  }

  bool objIsValid() const noexcept { return obj_.valid(); }

  const std::vector<Vertex_3d>& getObjVertexes() const { return obj_.vertexes; }

  const std::vector<Facet_3d>& getObjPolygons() const { return obj_.polygons; }

  s21::Vertex_3d getObjCenter() const { return obj_.center; }

  double getObjMaxValue() const { return obj_.max_value; }

  void reset() noexcept { obj_.clear(); }

 private:
  Obj obj_;
};
}  // namespace s21

#endif  //_3DVIEWER_SRC_CORE_MODEL_H_
