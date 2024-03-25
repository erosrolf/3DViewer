#include <QApplication>

#include "controller/controller.h"
#include "core/model.h"
#include "view/gl_view.h"
#include "view/main_widget.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWidget w;
  s21::Model model;
  s21::Controller controller(&model);
  w.show();
  return a.exec();
}
