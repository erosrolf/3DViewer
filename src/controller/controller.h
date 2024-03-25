#ifndef _3DVIEWER_SRC_CONTROLLER_CONTROLLER_H_
#define _3DVIEWER_SRC_CONTROLLER_CONTROLLER_H_

#include "../core/model.h"

namespace s21 {

class Controller {
 public:
  Controller() {}

  const Obj& openNewObj(const char* file_name) {
    const Obj& obj = model_calculator_.openNewObj(file_name);
    return obj;
  }

  void objMoveToRight(double value) { model_calculator_.objMoveToRight(value); }

  void objMoveToLeft(double value) { model_calculator_.objMoveToLeft(value); }

  void objMoveUp(double value) { model_calculator_.objMoveUp(value); }

  void objMoveDown(double value) { model_calculator_.objMoveDown(value); }

  void objMoveForward(double value) { model_calculator_.objMoveForward(value); }

  void objMoveBack(double value) { model_calculator_.objMoveBack(value); }

  void objRotateAroundX(double sin_angle, double cos_angle) {
    // model_calculator_.objRotateAroundX(sin_angle, cos_angle);
  }

  void objRotateAroundY(double sin_angle, double cos_angle) {
    // model_calculator_.objRotateAroundY(sin_angle, cos_angle);
  }

  void objRotateAroundZ(double sin_angle, double cos_angle) {
    // model_calculator_.objRotateAroundZ(sin_angle, cos_angle);
  }

  void screenshot() {
    // some instruction
  }
  void gifRecord() {
    // some instruction
  }

  Model model_calculator_;
};

}  // namespace s21
#endif  //_3DVIEWER_SRC_CONTROLLER_CONTROLLER_H_
