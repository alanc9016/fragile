#include "user.h"

/**
 * @brief badinputexception::badinputexception
 * Initialize errmsg to "There's a problem with your input"
 */
//badinputexception::badinputexception(){
//    errmsg = "There's a problem with your input";
//}
/**
 * @brief badinputexception::badinputexception
 * Initialize errmsg to passed qstring
 * @param q - Error message
 */
//badinputexception::badinputexception(QString q){
//    errmsg = q;
//}
/**
 * @brief badinputexception::getEx
 * @return errmsg - Error message
 */
//QString badinputexception::getEx(){
//    return errmsg;
//}
/**
 * @brief user::user
 * Initialize username and password to "default"
 * Initialize usertype set to "regular"
 */
user::user():username("Default"),
    password("default")
{
    valid = new QString("invalid");
}

/**
 * @brief user::~user
 * destructor
 */
user::~user()
{
    delete valid;
}

/**
 * @brief user::user
 * Initialize username and password to the parameters given.
 * User type is set to "regular"
 * @param u - Username
 * @param p - Password
 */
user::user(QString u, QString p):
    username(u), password(p)
{
    valid = new QString("user");
    QSqlQuery query;
    query.exec("Select * from user");
    while(query.next())
    {
        if(username==query.value(0).toString())
        {
            if(password==query.value(1).toString())
            {
                *valid = "valid";
            }
            else
                *valid = "password";
        }
    }
}
/**
 * @brief user::user
 * copy constructor
 * @param u
 * user object to be copied
 */
user::user(const user& u)
{
    username = u.username;
    password = u.password;
    valid = u.valid;
}

/**
 * @brief user::getUsername
 * Gets the username
 * @return - string username
 */
QString user::getUsername()
{
    return username;
}

/**
 * @brief user::setUsername
 * Sets the username
 * @param u - desired username
 */
void user::setUsername(QString u){
    username = u;
}

/**
 * @brief user::setPassword
 * Sets the password
 * @param p - desired password
 */
void user::setPassword(QString p){
    password = p;
}

/**
 * @brief user::setUserType
 * Sets the usertype
 * @param t - Executive or Regular
 */
void user::setValid(QString* t){
    valid = t;
}

/**
 * @brief user::getPassword
 * Gets the user password
 * @return - string password
 */
QString user::getPassword()
{
    return password;
}

/**
 * @brief user::getUserType
 * Gets usertype
 * @return - string usertype
 */
QString* user::getValid()
{
    return valid;
}
/**
 * @brief user::elevation
 * Checks if user is an admin or manager
 * - used for admin panel display
 * @return - return false
 */
bool user::elevation()
{
    return false;
}

/**
 * @brief admin::admin
 * @param u
 * user object to be copied if it is valid
 */
admin::admin(user& u)
{
    if(*(u.getValid())=="valid"){
       setUsername(u.getUsername());
       setPassword(u.getPassword());
       setValid(new QString(*(u.getValid())));
    }
    else
        throw QString("Try entering a valid " + *getValid());
}

/**
 * @brief user::elevation
 * Checks if user is an admin or manager
 * - used for admin panel display
 * @return - return true
 */
bool admin::elevation(){
    return true;
}
