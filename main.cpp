#include <QtGui/QApplication>
#include <QLocale>
#include <QTranslator>
#include "Books.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // loading proper location
    QString filename = QString("Books_%1").arg(QLocale::system().name());
    QTranslator translator;
    translator.load(filename.toLower(),qApp->applicationDirPath());
    a.installTranslator(&translator);
    Books w;
#if defined(Q_WS_S60)
    w.showMaximized();
#else
    w.show();
#endif
    return a.exec();
}
