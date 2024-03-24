#ifndef _3DVIEWER_SRC_CONTROLLER_CONTROLLER_H_
#define _3DVIEWER_SRC_CONTROLLER_CONTROLLER_H_

#include "../core/model.h"

namespace s21 {

class Controller {
public:
  Model model_calculator_;

  void openNewObj(const char* file_name) {
    model_calculator_.openNewObj(file_name);
  }
  
  void objMoveToRight(double value) {
    model_calculator_.objMoveToRight(value);
  }
  
  void objMoveToLeft(double value) {
    model_calculator_.objMoveToLeft(value);
  }
  
  void objMoveUp(double value) {
    model_calculator_.objMoveUp(value);
  }
  
  void objMoveDown(double value) {
    model_calculator_.objMoveDown(value);
  }
  
  void objMoveForward(double value) {
    model_calculator_.objMoveForward(value);
  }
  
  void objMoveBack(double value) {
    model_calculator_.objMoveBack(value);
  }
};

} // namespace s21
#endif  //_3DVIEWER_SRC_CONTROLLER_CONTROLLER_H_
