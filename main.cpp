 #include "bookwindow.h"

 #include <QtGui>

 int main(int argc, char * argv[])
 {
     Q_INIT_RESOURCE(books);

     QApplication app(argc, argv);

     BookWindow win;
     win.show();

     return app.exec();
 }
