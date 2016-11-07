#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD:mainwindow.h
#include <QMessageBox>
=======
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql>
#include <QTextStream>
#include <QVector>
#include <iostream>
#include "customer.h"
>>>>>>> origin/Ryan:GUI/mainwindow.h

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_adminLogBtn_clicked();
    void on_helpBtn_clicked();
    void on_purchaseBtn_clicked();

private:
    Ui::MainWindow *ui;
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
