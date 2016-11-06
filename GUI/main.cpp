#include "mainwindow.h"
#include <QApplication>

/**
 * @brief main - main method, used to create database and run gui
 * @param argc - number of chars passed
 * @param argv - char array passed as pointer
 * @return should return zero
 */
int main(int argc, char *argv[])
{
    createDatabase();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
