#ifndef _3DVIEWER_SRC_CONTROLLER_CONTROLLER_H_
#define _3DVIEWER_SRC_CONTROLLER_CONTROLLER_H_

#include <QImage>
#include <QOpenGLWidget>
#include <QString>

#include "../core/model.h"

namespace s21 {

class Controller {
 public:
  Controller(Model* m) : model_(m) {}

  const Obj& openNewObj(const char* file_name) {
    const Obj& obj = model_->openNewObj(file_name);
    return obj;
  }

  void objMoveToRight(double value) { model_->objMoveToRight(value); }

  void objMoveToLeft(double value) { model_->objMoveToLeft(value); }

  void objMoveUp(double value) { model_->objMoveUp(value); }

  void objMoveDown(double value) { model_->objMoveDown(value); }

  void objMoveForward(double value) { model_->objMoveForward(value); }

  void objMoveBack(double value) { model_->objMoveBack(value); }

  void objZoom(double value) { model_->objZoom(value); }

  void objRotateAroundX(double value) { model_->objRotateAroundX(value); }

  void objRotateAroundY(double value) { model_->objRotateAroundY(value); }

  void objRotateAroundZ(double value) { model_->objRotateAroundZ(value); }

  void objCentering() { model_->objCentering(); }

  void screenshot(QOpenGLWidget& view, QString screenshot_name) {
    QImage screenshot = view.grabFramebuffer();
    screenshot.save(screenshot_name);
  }

  bool objIsValid() const noexcept { return model_->objIsValid(); }

  void objReset() noexcept { model_->reset(); }

  const std::vector<Vertex_3d>& getObjVertexes() const {
    return model_->getObjVertexes();
  }

  const std::vector<Facet_3d>& getObjPolygons() const {
    return model_->getObjPolygons();
  }

  const s21::Vertex_3d getObjCenter() const { return model_->getObjCenter(); }

  const double getObjMaxValue() const { return model_->getObjMaxValue(); }

 private:
  Model* model_;
};

}  // namespace s21
#endif  //_3DVIEWER_SRC_CONTROLLER_CONTROLLER_H_
