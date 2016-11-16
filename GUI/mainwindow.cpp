#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//
// PAMPHLET PAGE
//

/**
 * @brief MainWindow::on_helpBtn_clicked
 * -----------------------------------------------------------------
 * This button prompts a widget which provides help to the user
 * regarding how to use the application.
 **/
void MainWindow::on_helpBtn_clicked()
{
    QMessageBox help;

    help.information(this,"Instructions","To purchase a robot click the \"Purchase a Robot\" button,\n"
                                         "although if you're an administrator, click on the \"Admin?\" "
                                         "button to be directed to the login page.");
}

/**
 * @brief MainWindow::on_adminLogBtn_clicked
 * ------------------------------------------------------------
 * This button moves the administrator to a new window
 * from which they can log into the admin portal by inputting
 * their log-in information.
 **/
void MainWindow::on_adminLoginBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->adminLoginPage);
    ui->adminUserLE->setFocus();
}

/**
 * @brief MainWindow::on_purchaseBtn_clicked
 * -------------------------------------------------------------------
 * This button sends the user to another window which shows them
 * four different options to purchase a robot. Each robot's listing
 * includes its name, price, and quantity.
 **/
void MainWindow::on_purchaseBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->purchasePage);
}

//
// PURCHASE LANDING PAGE
//

/**
 * @brief MainWindow::on_pBackBtn_clicked
 * ------------------------------------------------------------
 *
 **/
void MainWindow::on_pBackBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->landingPage);
}

//
// ADMIN LOG-IN PAGE
//

/**
 * @brief MainWindow::on_backBtn_clicked
 * -------------------------------------------------------------
 * This button will go back to the pamphlet page in case a user
 * accidentally clicks on it, or the admin wants to go back.
 **/
void MainWindow::on_aBackBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->landingPage);
    ui->adminUserLE->clear();
    ui->adminPassLE->clear();

}

/**
 * @brief MainWindow::on_adminUserLE_returnPressed
 * ------------------------------------------------------
 *
 **/
void MainWindow::on_adminUserLE_returnPressed()
{
    ui->adminPassLE->setFocus();
}

/**
 * @brief MainWindow::on_adminPassLE_returnPressed
 * ------------------------------------------------------
 *
 **/
void MainWindow::on_adminPassLE_returnPressed()
{
    ui->loginBtn->click();
}

/**
 * @brief MainWindow::on_loginBtn_clicked
 * ------------------------------------------------------
 *
 **/
void MainWindow::on_loginBtn_clicked()
{

}

//
// ADMIN LANDING PAGE
//

/**
 * @brief MainWindow::on_logOutBtn_clicked
 * ----------------------------------------------------------
 *
 **/
void MainWindow::on_logOutBtn_clicked()
{
    QMessageBox::StandardButton reply;

    // Displays a message box
    reply = QMessageBox::warning(this, tr("Logout"),
            tr("Are you sure you want to logout?"),
            QMessageBox::Ok | QMessageBox::Cancel);

    // Logout will return to login page
    if(QMessageBox::Ok == reply)
    {
        ui->stackedWidget->setCurrentWidget(ui->adminLoginPage);
        ui->adminUserLE->setFocus();
    }
}

/**
 * @brief MainWindow::on_viewListBtn_clicked
 * ----------------------------------------------------------
 *
 **/
void MainWindow::on_viewListBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->printCostumers);

    ui->tableWidget_printCustomers->setColumnWidth(0,179);
    ui->tableWidget_printCustomers->setColumnWidth(1,175);
    ui->tableWidget_printCustomers->setColumnWidth(2,125);
    ui->tableWidget_printCustomers->setColumnWidth(3,50);
    ui->tableWidget_printCustomers->setColumnWidth(4,60);
    ui->tableWidget_printCustomers->setColumnWidth(5,150);
    ui->tableWidget_printCustomers->setColumnWidth(6,100);
    ui->tableWidget_printCustomers->setColumnWidth(7,125);
    ui->tableWidget_printCustomers->setColumnWidth(8,125);
    ui->tableWidget_printCustomers->setColumnWidth(9,50);

    ui->tableWidget_printCustomers->setEnabled(true);
    ui->tableWidget_printCustomers->setSortingEnabled(false);

    QVector<customer> allCustomers = totalCustomers.getCustomers();

    QVector<customer>::iterator itCustomers = allCustomers.begin();

    ui->tableWidget_printCustomers->setRowCount(allCustomers.size());

    QTableWidgetItem *item;

    for(int row = 0; row < signed(allCustomers.size()); row++)
    {
        ui->tableWidget_printCustomers->setItem(row,0,new QTableWidgetItem(itCustomers->getName()));
        ui->tableWidget_printCustomers->setItem(row,1,new QTableWidgetItem(itCustomers->getStreet()));
        ui->tableWidget_printCustomers->setItem(row,2,new QTableWidgetItem(itCustomers->getCity()));
        ui->tableWidget_printCustomers->setItem(row,3,new QTableWidgetItem(itCustomers->getState()));
        ui->tableWidget_printCustomers->setItem(row,4,new QTableWidgetItem(itCustomers->getZip()));
        ui->tableWidget_printCustomers->setItem(row,5,new QTableWidgetItem(itCustomers->getInterest()));
        ui->tableWidget_printCustomers->setItem(row,6,new QTableWidgetItem(itCustomers->getStatus()));
        ui->tableWidget_printCustomers->setItem(row,7,new QTableWidgetItem(itCustomers->getTestimonial()));
        ui->tableWidget_printCustomers->setItem(row,8,new QTableWidgetItem(itCustomers->getRequested()));
        if(itCustomers->getActive())
            ui->tableWidget_printCustomers->setItem(row,9,new QTableWidgetItem("Yes"));
        else
            ui->tableWidget_printCustomers->setItem(row,9,new QTableWidgetItem("No"));
        itCustomers++;
    }

    ui->tableWidget_printCustomers->setSortingEnabled(true);

}

/**
 * @brief MainWindow::on_addDeleteCustomerBtn_clicked
 * ----------------------------------------------------------
 *
 **/
void MainWindow::on_addDeleteCustomerBtn_clicked()
{

}

/**
 * @brief MainWindow::on_updateListBtn_clicked
 * ----------------------------------------------------------
 *
 **/
void MainWindow::on_updateListBtn_clicked()
{

}

//Ordering the iRobots
void MainWindow::on_purchasePushButton_clicked()
{
    QString namePurchaser = ui->namePurchaserLineEdit->text();
    customer verifiedCustomer;

    qDebug() << "\n\nnamePurchaser: " << namePurchaser << endl;

    try
    {
        verifiedCustomer = irobots.getCustomer(namePurchaser);

        qDebug() << "verifiedCustomer.getName(): " << verifiedCustomer.getName() << endl;
        qDebug() << "ui->numRobot1Purch->currentText(): " << ui->numRobot1Purch->currentText() << endl;
        qDebug() << "ui->numRobot2Purch->currentText(): " << ui->numRobot2Purch->currentText() << endl;
        qDebug() << "ui->numRobot3Purch->currentText(): " << ui->numRobot3Purch->currentText() << endl;

        //If no robots are selected to be purchased but purchase button is still clicked..
        if(ui->numRobot1Purch->currentText()=="0" && ui->numRobot2Purch->currentText()=="0" && ui->numRobot3Purch->currentText()=="0")
        {
            QMessageBox::warning(this,"ERROR","Must purchase at least one robot.");
        }
        else
        {
            //Updating number of robots bought
            verifiedCustomer.setRobot1(ui->numRobot1Purch->currentText().toInt());
            verifiedCustomer.setRobot2(ui->numRobot2Purch->currentText().toInt());
            verifiedCustomer.setRobot3(ui->numRobot3Purch->currentText().toInt());

            QMessageBox::information(this,"Success","Your order has been submitted, thank you!");

        }

    }
    catch (QString)
    {
        QMessageBox::warning(this,"ERROR","Customer not found!");
    }
}


void MainWindow::on_BackButton_printCustomers_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->adminPage);
}

void MainWindow::on_testimonialsBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->TestimonialsPage);

    ui->tableWidget_testimonials->setColumnWidth(0,180);
    ui->tableWidget_testimonials->setColumnWidth(1,200);


}

void MainWindow::on_BackButton_Testimonials_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->landingPage);
}
