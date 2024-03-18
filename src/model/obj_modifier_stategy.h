#ifndef SRC_3DVIEWER_MODEL_OBJ_MODIFIER_STRATEGY_H_
#define SRC_3DVIEWER_MODEL_OBJ_MODIFIER_STRATEGY_H_

namespace s21 {

class Obj;

class ObjModifier {
 public:
  virtual ~ObjModifier() = default;
  virtual void Modify(Obj& obj) = 0;
};

class CentringStrategy : public ObjModifier {
 public:
  void Modify(Obj& obj) override;
  // TODO Написать алгоритм центрирования в .cc
};

class RotateStrategy : public ObjModifier {
 public:
  RotateStrategy(double x, double y, double z)
      : angle_x_(x), angle_y_(y), angle_z_(z) {}

  void Modify(Obj& obj) override;

 private:
  void rotateX(Obj& obj, double angle_x_);
  void rotateY(Obj& obj, double angle_y_);
  void rotateZ(Obj& obj, double angle_z_);
  double angle_x_, angle_y_, angle_z_;
};

class ScalingStrategy : public ObjModifier {
 public:
  ScalingStrategy(double s) : s_(s) {}

  void Modify(Obj& obj) override;

 private:
  double s_;
};

class TranslationStrategy : public ObjModifier {
 public:
  TranslationStrategy(double x, double y, double z);

  void Modify(Obj& obj) override;

 private:
  double x_, y_, z_;
};

}  // namespace s21

#endif  // SRC_3DVIEWER_MODEL_OBJ_MODIFIER_STRATEGY_H_
