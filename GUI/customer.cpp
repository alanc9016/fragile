#include "customer.h"
#include "mainwindow.h"
/**
 * @brief customer
 * Default constructor/never stored in db
 */
customer::customer():
    name("Default"),
    street("123 Default Way"),
    city("Default City"),
    state("DS"),
    zip("12345"),
    status("default"),
    interest("default"),
    testimonial("default testimonial"),
    requested("not requested"),
    isActive(true),
    robot1(0),
    robot2(0),
    robot3(0)
{}
/**
 * @brief customer
 * Constructor with all parameters except isActive, that is asssumed true
 * @param a
 * name will be set to a
 * @param b
 * street will be set to b
 * @param c
 * city will be set to c
 * @param d
 * state will be set to d
 * @param e
 * zip will be set to e
 * @param f
 * status will be set to f
 * @param g
 * interest will be set to g
 * @param h
 * testimonial will be set to h
 * @param i
 * requested will be set to i
 */
customer::customer(QString a, QString b , QString c, QString d, QString e, QString f, QString g, QString h, QString i,
                   int r1, int r2, int r3):
    name(a), street(b), city(c), state(d), zip(e), status(f), interest(g), testimonial(h), requested(i), isActive(true),
    robot1(r1), robot2(r2),robot3(r3)
{
}


/**
 * @brief customer
 * Customer with name and address passed, likely to be the most used
 * @param nm
 * name will be set to nm
 * @param str
 * street will be set to str
 * @param cty
 * city will be set to cty
 * @param sta
 * state will be set to sta
 * @param zp
 * zip will be set to zp
 * @param sts
 */
customer::customer(QString nm, QString str, QString cty, QString sta, QString zp, QString sts):
    name(nm), street(str), city(cty), state(sta), zip(zp), status(sts), interest("somewhat interested"),
    testimonial(""), requested("not requested"), isActive(true),robot1(0),robot2(0),robot3(0)
{
    QRegExp ex("\\d*");
    QRegExp pr("[a-zA-Z ]*");
    if(!ex.exactMatch(zip))
        throw QString("Zip code can only be digits!");
    if(!pr.exactMatch(cty)||!pr.exactMatch(sta))
        throw QString("City and state can only contain letters of the alphabet.");
    if(nm.length() > MAXNAME || str.length() > MAXSTREET || cty.length() > MAXCITY
            || sta.length() > MAXSTATE || zp.length() > MAXZIP || sts.length() > MAXSTATUS)
        throw QString("Too long! Name, city, status can be 50 characters, street can be 75,"
                      " zip can be 5, and zip can be 2");
}

/**
 * @brief customer::getName
 * @return
 * name as QString
 */
QString customer::getName() const
{
    return name;
}

/**
 * @brief customer::getStreet
 * @return
 * street as QString
 */
QString customer::getStreet() const
{
    return street;
}

/**
 * @brief customer::getCity
 * @return
 * city as QString
 */
QString customer::getCity() const
{
    return city;
}

/**
 * @brief customer::getState
 * @return
 * state (postal) as QString
 */
QString customer::getState() const
{
    return state;
}

/**
 * @brief customer::getZip
 * @return
 * zipcode as int
 */
QString customer::getZip() const

{
    return zip;
}

/**
 * @brief customer::getStatus
 * @return
 * status of customer as QString
 */
QString customer::getStatus() const
{
    return status;
}

/**
 * @brief customer::getInterest
 * @return
 * interest as QString
 */
QString customer::getInterest() const
{
    return interest;
}

/**
 * @brief customer::getTestimonial
 * @return
 * testimonial of customer as QString
 */
QString customer::getTestimonial() const
{
    return testimonial;
}

/**
 * @brief customer::getRequested
 * @return
 * the request status of customer as QString
 */
QString customer::getRequested() const
{
    return requested;
}

/**
 * @brief customer::getActive
 * @return
 * active(true) or inactive(false)
 */
bool customer::getActive() const
{
    return isActive;
}
/**
 * @brief customer::getRobot1
 * @return
 * amount of robot1's ordered
 */
int customer::getRobot1() const
{
    return robot1;
}
/**
 * @brief customer::getRobot2
 * @return
 * amount of robot2's ordered
 */
int customer::getRobot2() const
{
    return robot2;
}
/**
 * @brief customer::getRobot3
 * @return
 * amount of robot3's ordered
 */
int customer::getRobot3() const
{
    return robot3;
}

/**
 * @brief customer::setName
 * @param n
 * the value name will be set to
 * @exception QString() Value too large
 */
void customer::setName(QString n)
{
    if(n.length() > MAXNAME)
        throw QString("Name longer than " + QString::number(MAXNAME) + " characters.");
    QSqlQuery query;
    query.exec("UPDATE customer SET name='"+n+"' where name='"+name+"'");
    name = n;
}

/**
 * @brief customer::operator =
 * @param s
 * the value name will be set to
 */
void customer::operator =(QString s)
{
    setName(s);
}

/**
 * @brief customer::setStreet
 * @param s
 * the value street will be set to
 * @exception QString() Value too large
 */
void customer::setStreet(QString s)
{
    if(s.length() > MAXSTREET)
        throw QString("Street longer than " + QString::number(MAXSTREET) + " characters.");
    QSqlQuery query;
    query.exec("UPDATE customer SET street='"+s+"' where name='"+name+"'");
    street = s;
}

/**
 * @brief customer::setCity
 * @param c
 * the value city will be set to
 * @exception QString() Value too large
 */
void customer::setCity(QString c)
{
    QRegExp ex("[a-zA-Z]*");
    if(c.length() > MAXCITY)
        throw QString("City longer than " + QString::number(MAXCITY) + " characters.");
    if(!ex.exactMatch(c))
        throw QString("City must be composed of characters only!");
    QSqlQuery query;
    query.exec("UPDATE customer SET city='"+c+"' where name='"+name+"'");
    city = c;
}

/**
 * @brief customer::setState
 * @param s
 * the value state will be set to
 * @exception QString() Value too large or invalid characters
 */
void customer::setState(QString s)
{
    QRegExp ex("[a-zA-Z]*");
    qDebug() << s.length() << endl;
    if(s.length() > MAXSTATE)
        throw QString("State longer than " + QString::number(MAXSTATE) + " characters.");
    if(!ex.exactMatch(s))
        throw QString("State must be composed of two characters!");
    QSqlQuery query;
    query.exec("UPDATE customer SET state='"+s+"' where name='"+name+"'");
    state = s;
}

/**
 * @brief customer::setZip
 * @param z
 * the value zip will be set to
 * @exception QString() Value too large
 */
void customer::setZip(QString z)
{
    QRegExp ex("\\d*");
    if(z.length() > MAXZIP)
        throw QString("Zip longer than " + QString::number(MAXZIP) + " characters.");
    if(!ex.exactMatch(z))
        throw QString("Zip can only be composed of numbers");
    QSqlQuery query;
    query.exec("UPDATE customer SET zip='"+z+"' where name='"+name+"'");
    zip = z;
}

/**
 * @brief customer::setStatus
 * @param s
 * the value status will be set to
 * @exception QString() Value too large
 */
void customer::setStatus(QString s)
{
    if(s.length() > MAXSTATUS)
        throw QString("Status longer than " + QString::number(MAXSTATUS) + " characters.");
    QSqlQuery query;
    query.exec("UPDATE customer SET status='"+s+"' where name='"+name+"'");
    status = s;
}

/**
 * @brief customer::setInterest
 * @param i
 * the value interest will be set to
 * @exception QString() Value too large
 */
void customer::setInterest(QString i)
{
    if(i.length() > MAXINTEREST)
        throw QString("Interest longer than " + QString::number(MAXINTEREST) + " characters.");
    QSqlQuery query;
    query.exec("UPDATE customer SET interest='"+i+"' where name='"+name+"'");
    interest = i;
}

/**
 * @brief customer::setTestimonial
 * @param t
 * the value testimonial will be set to
 * @exception QString() Value too large
 */
void customer::setTestimonial(QString t)
{
    if(t.length() > MAXTEST)
        throw QString("Testimonial longer than " + QString::number(MAXTEST) + " characters.");
    QSqlQuery query;
    query.exec("UPDATE customer SET testimonial='"+t+"' where name='"+name+"'");
    testimonial = t;
}

/**
 * @brief customer::setRequested
 * @param r
 * the value requested will be set to
 * @exception QString() Value too large
 */
void customer::setRequested(QString r)
{
    if(r.length() > MAXREQ)
        throw QString("Request longer than " + QString::number(MAXREQ) + " characters.");
    QSqlQuery query;
    query.exec("UPDATE customer SET requested='"+r+"' where name='"+name+"'");
    requested = r;
}

/**
 * @brief customer::setActive
 * @param a
 * the value isActive will be set to
 */
void customer:: setActive(bool a)
{
    QSqlQuery query;
    query.exec("UPDATE customer SET isActive="+QString::number(a)+" where name='"+name+"'");
    isActive = a;
}

/**
 * @brief customer::operator %
 * @param a
 * determines if customer is active or not
 */
void customer::operator %(bool a)
{
    setActive(a);
}


/**
 * @brief customer::printCustomer
 * @param
 * prints out individual customer
 */
void customer:: printCustomer()const
{
     QTextStream(stdout) << "\nName:       " << getName();
     QTextStream(stdout) << "\nStreet:     " << getStreet();
     QTextStream(stdout) << "\nCity:       " << getCity();
     QTextStream(stdout) << "\nState:      " << getState();
     QTextStream(stdout) << "\nZip:        " << getZip();
     QTextStream(stdout) << "\nInterest:   " << getInterest();
     QTextStream(stdout) << "\nStatus:     " << getStatus();
     QTextStream(stdout) << "\nTestimonial " << getTestimonial();
     QTextStream(stdout) << "\nRequested:  " << getRequested();
     QTextStream(stdout) << "\nActive:     " << getActive();
     QTextStream(stdout) << "\n";

}
/** @brief customer::setRobot1
 *  @param r
 * @exception QString() Value negative
 */
void customer::setRobot1(int r)
{
    if(r < 0)
        throw QString("Value " + QString::number(r) + " is negative.");
    QSqlQuery query;
    query.exec("UPDATE customer SET robot1='"+QString::number(r)+"' where name='"+name+"'");
    robot1 = r;
}
/**
 * @brief customer::setRobot2
 * @param r
 * @exception QString() Value negative
 */
void customer::setRobot2(int r)
{
    if(r < 0)
        throw QString("Value " + QString::number(r) + " is negative.");
    QSqlQuery query;
    query.exec("UPDATE customer SET robot2='"+QString::number(r)+"' where name='"+name+"'");
    robot2 = r;
}
/**
 * @brief customer::setRobot3
 * @param r
 * @exception QString() Value negative
 */
void customer::setRobot3(int r)
{
    if(r < 0)
        throw QString("Value " + QString::number(r) + " is negative.");
    QSqlQuery query;
    query.exec("UPDATE customer SET robot3='"+QString::number(r)+"' where name='"+name+"'");
    robot3 = r;
}

