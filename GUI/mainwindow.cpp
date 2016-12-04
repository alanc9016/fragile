
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    custpointer = NULL;
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

void MainWindow::on_sendMessageBtn_clicked()
{
    QMessageBox sent;

    sent.information(this,"Thank you for contacting us.","We will get back to you as soon as possible.");
}

/**
 * @brief MainWindow::on_contactusBtn_clicked
 * contact button
 */
void MainWindow::on_contactusBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->contactPage);
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
 * go back to landing page
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
    user* status = new user(ui->adminUserLE->text(),
                            ui->adminPassLE->text());
    try
    {
        user* a = new admin(*status);
        status = a;
    }
    catch(QString x) {
        QMessageBox error;

        error.information(this,"Invalid Report","Please enter a valid username/password.");

        ui->adminUserLE->clear();
        ui->adminPassLE->clear();
        ui->adminUserLE->setFocus();
    }

    if(status->elevation())
    {
        ui->stackedWidget->setCurrentWidget(ui->adminPage);
        ui->adminUserLE->clear();
        ui->adminPassLE->clear();
    }
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
    ui->tableWidget_printCustomers->setColumnWidth(10,125);
    ui->tableWidget_printCustomers->setColumnWidth(11,125);
    ui->tableWidget_printCustomers->setColumnWidth(12,125);

    ui->tableWidget_printCustomers->setEnabled(true);
    ui->tableWidget_printCustomers->setSortingEnabled(false);

    QVector<customer> allCustomers = irobots.getCustomers();

    QVector<customer>::iterator itCustomers = allCustomers.begin();

    ui->tableWidget_printCustomers->setRowCount(allCustomers.size());

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
        ui->tableWidget_printCustomers->setItem(row,10,new QTableWidgetItem(QString::number(itCustomers->getRobot1())));
        ui->tableWidget_printCustomers->setItem(row,11,new QTableWidgetItem(QString::number(itCustomers->getRobot2())));
        ui->tableWidget_printCustomers->setItem(row,12,new QTableWidgetItem(QString::number(itCustomers->getRobot3())));
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
    ui->stackedWidget->setCurrentWidget(ui->addDelete);
    ui->addCustTable->clearContents();
    ui->uiDeleteCust->clear();
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

void MainWindow::on_testimonialBtn_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->testimonialPage);

    ui->label_error_empty_name->hide();
    ui->label_error_empty_testimonial->hide();
    ui->label__error_name_not_found->hide();

    ui->tableWidget_Testimonials->setColumnWidth(0,179);
    ui->tableWidget_Testimonials->setColumnWidth(1,200);

    QVector<customer> testimonialCustomers = irobots.getCustomers();
    QVector<customer>::iterator itCustomers = testimonialCustomers.begin();
    ui->tableWidget_Testimonials->setRowCount(testimonialCustomers.size());

    for(int row = 0; row < signed(testimonialCustomers.size()); row++)
    {
        ui->tableWidget_Testimonials->setItem(row,0,new QTableWidgetItem(itCustomers->getName()));
        ui->tableWidget_Testimonials->setItem(row,1,new QTableWidgetItem(itCustomers->getTestimonial()));
        itCustomers++;
    }
}

void MainWindow::on_BackButton_testimonial_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->landingPage);
}

void MainWindow::on_pushButton_saveTestimonial_clicked()
{
    customer *temp;

    if(ui->lineEdit_TestimonialName->text().isEmpty() && ui->lineEdit_testimonial->text().isEmpty())
    {
        ui->label_error_empty_name->show();
        ui->label_error_empty_testimonial->show();
    }
    else if(ui->lineEdit_TestimonialName->text().isEmpty())
    {
        ui->label_error_empty_name->show();
        ui->label_error_empty_testimonial->hide();
    }

    else if(ui->lineEdit_testimonial->text().isEmpty())
    {
        ui->label_error_empty_testimonial->show();
        ui->label_error_empty_name->hide();
    }

    else
    {
        ui->label_error_empty_name->hide();
        ui->label_error_empty_testimonial->hide();
        ui->label__error_name_not_found->hide();

        temp = irobots.FindCustomer(ui->lineEdit_TestimonialName->text());

        if(temp == NULL)
            ui->label__error_name_not_found->show();
        else
        {
           temp->setTestimonial(ui->lineEdit_testimonial->text());

           ui->tableWidget_Testimonials->setColumnWidth(0,179);
           ui->tableWidget_Testimonials->setColumnWidth(1,200);

           QVector<customer> testimonialCustomers = irobots.getCustomers();
           QVector<customer>::iterator itCustomers = testimonialCustomers.begin();
           ui->tableWidget_Testimonials->setRowCount(testimonialCustomers.size());

           for(int row = 0; row < signed(testimonialCustomers.size()); row++)
           {
               ui->tableWidget_Testimonials->setItem(row,0,new QTableWidgetItem(itCustomers->getName()));
               ui->tableWidget_Testimonials->setItem(row,1,new QTableWidgetItem(itCustomers->getTestimonial()));
               itCustomers++;
           }
        }

    }
}
/**
 * @brief MainWindow::on_BackBtnContactus_2_clicked
 */
void MainWindow::on_BackBtnContactus_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->landingPage);
    ui->firstNameEdit->clear();
    ui->lastNameEdit->clear();
    ui->emailEdit->clear();
    ui->phoneEdit->clear();
    ui->messageTextBox->clear();
}

/**
 * @brief MainWindow::on_BackButton_editCustomers_clicked
 * Takes you back to admin window
 */
void MainWindow::on_BackButton_editCustomers_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->adminPage);
    custpointer = NULL;
}

/**
 * @brief MainWindow::on_editCustomerButton_clicked
 * Takes you to edit customer window
 */
void MainWindow::on_editCustomerButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->editCustomers);
    ui->basicTable->clearContents();
    ui->custInfoTable->clearContents();
    ui->custOrderTable->clearContents();
    ui->userInputEditCustomer->clear();
}

void MainWindow::on_userInputEditCustomer_returnPressed()
{
   if(!ui->userInputEditCustomer->text().isEmpty())
   {
        QString n = ui->userInputEditCustomer->text();
        try{
            customer temp = irobots.getCustomer(n);
            custpointer = NULL;
            custpointer = irobots.FindCustomer(n);
            ui->basicTable->setItem(0,0,new QTableWidgetItem(temp.getName()));
            ui->basicTable->setItem(0,1,new QTableWidgetItem(temp.getStreet()));
            ui->basicTable->setItem(0,2,new QTableWidgetItem(temp.getCity()));
            ui->basicTable->setItem(0,3,new QTableWidgetItem(temp.getState()));
            ui->basicTable->setItem(0,4,new QTableWidgetItem(temp.getZip()));

            ui->custInfoTable->setItem(0,0, new QTableWidgetItem(temp.getInterest()));
            ui->custInfoTable->setItem(0,1, new QTableWidgetItem(temp.getStatus()));
            ui->custInfoTable->setItem(0,2, new QTableWidgetItem(temp.getTestimonial()));
            ui->custInfoTable->setItem(0,3, new QTableWidgetItem(temp.getRequested()));

            ui->custOrderTable->setItem(0,0, new QTableWidgetItem(QString::number(temp.getRobot1())));
            ui->custOrderTable->setItem(0,1, new QTableWidgetItem(QString::number(temp.getRobot2())));
            ui->custOrderTable->setItem(0,2, new QTableWidgetItem(QString::number(temp.getRobot3())));
        }
        catch (QString)
        {
            QMessageBox::warning(this,"ERROR","Customer not found!");
        }
   }
}


/**
 * @brief MainWindow::on_basicTable_cellChanged
 * will allow easy, protected editing of address of customer object
 * @param row
 * @param column
 */
void MainWindow::on_basicTable_cellChanged(int row, int column)
{
    try{
        if(custpointer != NULL){
            QString tmp = ui->basicTable->item(row, column)->text();
            switch (column) {
            case 0:
                if(tmp != custpointer->getName())
                    custpointer->setName(tmp);
                break;
            case 1:
                if(tmp != custpointer->getStreet())
                    custpointer->setStreet(tmp);
                break;
            case 2:
                if(tmp != custpointer->getCity())
                    custpointer->setCity(tmp);
                break;
            case 3:
                if(tmp != custpointer->getState())
                    custpointer->setState(tmp);
                break;
            case 4:
                if(tmp != custpointer->getZip())
                    custpointer->setZip(tmp);
                break;
            default:
                qDebug() << "Something went wrong" << endl;
                qDebug() << "custpointer: " << custpointer->getName() << endl;
                qDebug() << "row: " << row << "  col: " << column << endl;
                break;
            }
        }
    }
    catch(QString x){
         QMessageBox::warning(this,"ERROR",x);
    }
}

/**
 * @brief MainWindow::on_custInfoTable_cellChanged
 * will allow easy, protected editing of text fields related to customer object
 * @param row
 * @param column
 */
void MainWindow::on_custInfoTable_cellChanged(int row, int column)
{
    try{
        if(custpointer != NULL){
            QString tmp = ui->custInfoTable->item(row, column)->text();
            switch (column) {
            case 0:
                if(tmp != custpointer->getInterest())
                    custpointer->setInterest(tmp);
                break;
            case 1:
                if(tmp != custpointer->getStatus())
                    custpointer->setStatus(tmp);
                break;
            case 2:
                if(tmp != custpointer->getTestimonial())
                    custpointer->setTestimonial(tmp);
                break;
            case 3:
                if(tmp != custpointer->getRequested())
                    custpointer->setRequested(tmp);
                break;
            default:
                qDebug() << "Something went wrong" << endl;
                qDebug() << "custpointer: " << custpointer->getName() << endl;
                qDebug() << "row: " << row << "  col: " << column << endl;
                break;
            }
        }
    }
    catch(QString x){
         QMessageBox::warning(this,"ERROR",x);
    }

}

void MainWindow::on_custOrderTable_cellChanged(int row, int column)
{
    try{
        if(custpointer != NULL){
            int tmp = ui->custOrderTable->item(row, column)->text().toInt();
            switch (column) {
            case 0:
                if(tmp != custpointer->getRobot1()){
                    custpointer->setRobot1(tmp);
                }
                break;
            case 1:
                if(tmp != custpointer->getRobot2()){
                    custpointer->setRobot2(tmp);
                }
                break;
            case 2:
                if(tmp != custpointer->getRobot3()){
                    custpointer->setRobot3(tmp);
                }
                break;
            default:
                qDebug() << "Something went wrong" << endl;
                qDebug() << "custpointer: " << custpointer->getName() << endl;
                qDebug() << "row: " << row << "  col: " << column << endl;
                break;
            }
        }
    }
    catch(QString x){
         QMessageBox::warning(this,"ERROR",x);
    }

}

/**
 * @brief MainWindow::on_BackButton_addDelete_clicked
 * return from add/delete page to admin page
 */
void MainWindow::on_BackButton_addDelete_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->adminPage);
}

void MainWindow::on_uiDeleteCust_returnPressed()
{
    if(!ui->uiDeleteCust->text().isEmpty())
    {
        try
        {
            irobots.deleteCustomer(ui->uiDeleteCust->text());
            QMessageBox::information(this,"Success",
                                     ui->uiDeleteCust->text() + " has been deleted!");
        }
        catch(QString x){
             QMessageBox::warning(this,"ERROR",x);
        }
    }

}

void MainWindow::on_addCustButton_clicked()
{
    try
    {
        QString nme = ui->addCustTable->item(0,0)->text();
        QString str = ui->addCustTable->item(0,1)->text();
        QString cty = ui->addCustTable->item(0,2)->text();
        QString sta = ui->addCustTable->item(0,3)->text();
        QString zip = ui->addCustTable->item(0,4)->text();
        QString sts = ui->addCustTable->item(0,5)->text();

        if(!nme.isEmpty() && !str.isEmpty() && !cty.isEmpty() && !sta.isEmpty() && !sts.isEmpty())
        {
            irobots.addCustomer(customer(nme, str, cty, sta, zip, sts));
            QMessageBox::information(this, "Success!", nme + " was added to the customerlist!");
        }
    }
    catch(QString ex)
    {
        QMessageBox::warning(this, "ERROR", ex);
    }
}
