#include "view/main_widget.h"

#include <QApplication>
#include "view/gl_view.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    w.show();
    return a.exec();
}
