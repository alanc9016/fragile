#include "customer.h"
#include "mainwindow.h"
customerlist::customerlist()
{
    QSqlQuery query;
    query.exec("SELECT name, street, city, state, zip, status, interest, testimonial, requested, isActive,"
               "robot1, robot2, robot3 from customer");
    while (query.next()) {
        if(query.value(9).toBool())
            customers.push_back(customer(query.value(0).toString(), query.value(1).toString(), query.value(2).toString(),
                                     query.value(3).toString(), query.value(4).toString(), query.value(5).toString(),
                                     query.value(6).toString(), query.value(7).toString(), query.value(8).toString(),
                                         query.value(10).toInt(), query.value(11).toInt(), query.value(12).toInt()));
    }
}

customerlist::customerlist(QString q)
{
    QSqlQuery query;
    query.exec(q);
    while(query.next()){
        if(query.value(9).toBool())
            customers.push_back(customer(query.value(0).toString(), query.value(1).toString(), query.value(2).toString(),
                                     query.value(3).toString(), query.value(4).toString(), query.value(5).toString(),
                                     query.value(6).toString(), query.value(7).toString(), query.value(8).toString(),
                                         query.value(10).toInt(), query.value(11).toInt(), query.value(12).toInt()));
    }
}

customer customerlist::getCustomer(const QString& nm)
{
    for(auto it = customers.begin(), end = customers.end(); it != end; ++it) {
        if(nm == it->getName())
        {
            return *it;
        }
    }
    throw QString("Error: No Customer by name of " + nm + " exists!");
    return customer();
}

void customerlist::printCustomers()const
{
    QVector<customer>::const_iterator it = customers.begin();

    while(it != customers.end())
    {
        it->printCustomer();
        it++;
    }
}

/**
 * @brief customerlist::addCustomer
 * @param c
 * customer to be added to list
 */
void customerlist::addCustomer(const customer& c)
{
    try{
        getCustomer(c.getName());
        QTextStream(stdout) << c.getName() << " already exists in database!" << endl;
    }
    catch(QString ex){
        QSqlQuery query;
        query.exec("INSERT INTO customer (name, street, city, state, zip, interest,"
               "status, testimonial, requested, robot1, robot2, robot3)"
               "VALUES('"+c.getName()+"','"+c.getStreet()+"','"+c.getCity()+"',"
               "'"+c.getState()+"','"+c.getZip()+"','"+c.getInterest()+"','"+c.getStatus()+"','"+c.getTestimonial()+"',"
               "'"+c.getRequested()+"',"+
               QString::number(c.getRobot1())+","+QString::number(c.getRobot2())+","+
               QString::number(c.getRobot3())+")");
        customers.push_back(c);
    }
}
/**
 * @brief customerlist::deleteCustomer
 * deletes customer of name s from the customer list,
 * as well as soft delete from database (set active to 0)
 * @param s
 * name of customer to be deleted
 */
void customerlist::deleteCustomer(QString s)
{
    auto it = customers.begin();
    int i = 0;
    bool notDeleted = true;
    while(it != customers.end() && notDeleted)
    {
        if(it->getName() == s)
        {
            QSqlQuery query;
            query.exec("UPDATE customer set isActive=0 where name="+customers.at(i).getName());
            customers.remove(i);
            notDeleted = false;
        }
        ++it;
        ++i;
    }
    if(notDeleted==true)
        throw QString("No customer by name of "+s+" exists!");
}
QVector<customer> customerlist::getCustomers()const
{
    QVector<customer> totalCustomers;
    QVector<customer>::const_iterator it = customers.begin();

    while(it != customers.end())
    {
        totalCustomers.push_back((*it));
        it++;
    }

    return totalCustomers;
}
customer* customerlist::FindCustomer(QString customerName)
{
    for(auto i = customers.begin(); i != customers.end(); ++i)
        if(i->getName() == customerName)
            return &(*i);

    return nullptr;
}
