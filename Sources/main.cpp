#include "MainWindow.h"
#include <QDebug>
#include <QFile>
#include <QSaveFile>
#include <QSet>

#include <QApplication>
#include <QTextStream>

int main(int argc, char* argv[]) {

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
