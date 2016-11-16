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
    QTextStream(stdout) << QDir::currentPath() << endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    try{
        user* test = new user("admin","admin");
        user* ad = new admin(*test);
        test = ad;
        QTextStream(stdout) << "\n" << QString::number(test->elevation()) << "\n";
        w.irobots.addCustomer(customer(QString("Name"),QString("street"),QString("city"),QString("state"),
                                   QString("9234"), QString("h"),QString("df"),QString("egf"),
                                   QString("req"), 1, 2, 0));
        QTextStream(stdout) << w.irobots.getCustomer("Name").getCity();
        //w.irobots.deleteCustomer("Name");
    }
    catch(QString ex){
        QTextStream(stdout) << "\n" << ex << "\n";
    }


    return a.exec();
}
