#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QTextStream>
#include <QVector>
#include <iostream>
#include <QMessageBox>
#include <QRegExp>
#include <QDebug>
#include "user.h"
#include "customer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    customerlist irobots;
    ~MainWindow();

private slots:
    void on_helpBtn_clicked();
    void on_purchaseBtn_clicked();
    void on_adminLoginBtn_clicked();

    void on_pBackBtn_clicked();

    void on_aBackBtn_clicked();
    void on_adminUserLE_returnPressed();
    void on_adminPassLE_returnPressed();
    void on_loginBtn_clicked();

    void on_logOutBtn_clicked();
    void on_viewListBtn_clicked();
    void on_addDeleteCustomerBtn_clicked();
    void on_updateListBtn_clicked();

    void on_purchasePushButton_clicked();

    void on_BackButton_printCustomers_clicked();

    void on_testimonialsBtn_clicked();

    void on_BackButton_Testimonials_clicked();

private:
    Ui::MainWindow *ui;
    customerlist totalCustomers;
};
/**
 * @brief createDatabase
 * Method for creating a database
 */
void createDatabase();
/**
 * @brief executeSQLFile
 * Will execute passed file
 * @param file
 * Relative path to .sql file
 */
void executeSQLFile(const QString&);

#endif // MAINWINDOW_H
