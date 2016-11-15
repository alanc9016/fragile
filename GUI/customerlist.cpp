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

<<<<<<< HEAD
void customerlist::printCustomers()const
{
    QVector<customer>::const_iterator it = customers.begin();

    while(it != customers.end())
    {
        it->printCustomer();
        it++;
    }
}

ostream& operator <<(ostream& output, const customer& outputCostumer)
{
    output << "Name\n";
    //output << outputCostumer.getName();

    return output;
=======
/**
 * @brief customerlist::addCustomer
 * @param c
 * customer to be added to list
 */
void customerlist::addCustomer(const customer& c)
{
    QSqlQuery query;
    query.exec("INSERT INTO customer (name, street, city, state, zip, interest,"
               "status, testimonial, requested, isActive, robot1, robot2, robot3)"
               "VALUES('"+c.getName()+"','"+c.getStreet()+"','"+c.getCity()+"',"
               "'"+c.getZip()+"','"+c.getInterest()+"','"+c.getStatus()+"','"+c.getTestimonial()+"',"
               "'"+c.getRequested()+"',"+QString::number(c.getActive())+","+
               QString::number(c.getRobot1())+","+QString::number(c.getRobot2())+","+
               QString::number(c.getRobot3())+")");
    customers.push_back(c);
}
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
>>>>>>> 28af310d5e8d7affd5591c3f688dcd2bad193552
}
