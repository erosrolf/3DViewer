#ifndef SRC_3DVIEWER_MODEL_OBJ_MODIFIER_STRATEGY_H_
#define SRC_3DVIEWER_MODEL_OBJ_MODIFIER_STRATEGY_H_

#include "obj.h"

namespace s21 {

class Obj;

class ObjModifier {
 public:
  virtual ~ObjModifier() = default;
  virtual void modify(Obj& obj) = 0;
};

class CentringStrategy : public ObjModifier {
 public:
  void modify(Obj& obj) override;
  // TODO Написать алгоритм центрирования в .cc
};

class RotateStrategy : public ObjModifier {
 public:
  enum class Type {
    X = 0,
    Y,
    Z,
  };

  RotateStrategy(Type type, double angle) : type_(type), angle_(angle) {}

  void modify(Obj& obj) override;

 private:
  using RotateFunction = void (RotateStrategy::*)(Vertex_3d&, double, double);

  void rotate(Obj& obj, double angle, RotateFunction rotateFunc);
  void rotateX(Vertex_3d& vertex, double sin_angle, double cos_angle);
  void rotateY(Vertex_3d& vertex, double sin_angle, double cos_angle);
  void rotateZ(Vertex_3d& vertex, double sin_angle, double cos_angle);

  Type type_;
  double angle_;
};

class ScalingStrategy : public ObjModifier {
 public:
  ScalingStrategy(double s) : s_(s) {}

  void modify(Obj& obj) override;

 private:
  double s_;
};

class TranslationStrategy : public ObjModifier {
 public:
  TranslationStrategy(double x, double y, double z);

  void modify(Obj& obj) override;

 private:
  double x_, y_, z_;
};

}  // namespace s21

#endif  // SRC_3DVIEWER_MODEL_OBJ_MODIFIER_STRATEGY_H_
