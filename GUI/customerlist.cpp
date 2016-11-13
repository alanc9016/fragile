#include "customer.h"
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
