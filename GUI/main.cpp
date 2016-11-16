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
    //QTextStream(stdout) << QDir::currentPath() << endl;
    //customerlist irobots;
    //QTextStream(stdout) << "zip of item in list " << irobots.getCustomer("FBI").getZip();
    //QTextStream(stdout) << QDir::currentPath() << endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    try{
        user* test = new user("admin","admin");
        user* ad = new admin(*test);
        test = ad;
        QTextStream(stdout) << "\n" << QString::number(test->elevation()) << "\n";
    }
    catch(QString ex){
        QTextStream(stdout) << "\n" << ex << "\n";
    }




    return a.exec();
}
