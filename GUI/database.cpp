#include "mainwindow.h"
/**
 * @brief createDatabase
 * Creates the SQLite database if there isn't one
 */
void createDatabase()
{
    //Check if database exists before we init it
    QFileInfo check_file("/Users/macowner/Desktop/fragile/fragile/irobots.db");
    bool exists = check_file.exists() && check_file.isFile();

    // connect to database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/macowner/Desktop/fragile/fragile/irobots.db");
    bool db_ok = db.open();
     QTextStream(stdout) << "Connecting to database" << endl;
    if(db_ok){
        QTextStream(stdout) << "All good" << endl;
    }

    //If the database doesn't exist, run the init queries
    if(!exists) {
        executeSQLFile("/Users/macowner/Desktop/fragile/fragile/createdb.sql");
        executeSQLFile("/Users/macowner/Desktop/fragile/fragile/data.sql");
    }
}
/**
 * @brief executeSQLFile
 * Will execute pre-made .sql files in order to create the database
 * @param file - the relative path to the .sql file
 */
void executeSQLFile(const QString &file){
    QSqlQuery query2;
    QFile fp(file);
    fp.open(QFile::ReadOnly|QFile::Text);
    QTextStream(stdout) << "Executing file: " << file;

    //Read in entire sql file
    QString q = fp.readAll();

    //Split each query into its own string
    QStringList queries = q.split(';');
    foreach (QString query, queries)
    {
        //Execute the induvidual query
        bool ret = query2.exec(query);

        if(!ret) {
             QTextStream(stdout) << query;
             QTextStream(stdout) << query2.lastError().text();
        }

        //Reset the query
        query2.finish();
    }
}

