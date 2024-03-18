#ifndef SRC_3DVIEWER_MODEL_OBJ_MODIFIER_STRATEGY_H_
#define SRC_3DVIEWER_MODEL_OBJ_MODIFIER_STRATEGY_H_

namespace s21 {

class Obj;

class ObjModifier {
 public:
  virtual ~ObjModifier() = default;
  virtual void Modify(Obj& obj) = 0;
};

class CentringStategy : public ObjModifier {
 public:
  void Modify(Obj& obj) override;
  // TODO Написать алгоритм центрирования в .cc
};

class ScalingStategy : public ObjModifier {
 public:
  void Modify(Obj& obj) override;
  // TODO Написать алгоритм масштабирования в .cc.
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
