#include <QApplication>

#include "controller/controller.h"
#include "core/model.h"
#include "view/gl_view.h"
#include "view/main_widget.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  s21::Model model;
  s21::Controller controller(&model);
  MainWidget main_widget(nullptr, &controller);
  main_widget.show();
  return a.exec();
}
