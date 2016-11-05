#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

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

#endif // MAINWINDOW_H
