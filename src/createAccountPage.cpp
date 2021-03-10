#include "header/createAccountPage.hpp"
#include "ui_createAccountPage.h"

#include <QtSql>
#include <QString>
#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionValidator>



CreateAccountPage::CreateAccountPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateAccountPage)
{
    ui->setupUi(this);
    //hide message
    ui->createAccountMessage->hide();
    //set up password field
    ui->passwordInput->setEchoMode(QLineEdit::Password);
    ui->retypePasswordInput->setEchoMode(QLineEdit::Password);

}

CreateAccountPage::~CreateAccountPage()
{
    delete ui;
}

bool CreateAccountPage::connectToAccountDB()
{
    //connect to DB driver
    db = QSqlDatabase::addDatabase("QSQLITE");
    //database name
    QString dbName = "Account.db3";
    //try to connect to database
    db.setDatabaseName(dbName);
    db.open();
    //if we are able to connected into the database
    if(db.isOpen())
    {
        qDebug() << "Successfully connected to the database";
        //set a new query
        QSqlQuery query = QSqlQuery(db);
        //create account table if it does not exist
        query.exec( "CREATE TABLE IF NOT EXISTS account ( id INTEGER PRIMARY KEY AUTOINCREMENT, userName TEXT, password TEXT, firstName TEXT, lastName TEXT, accountType INTEGER, items BLOB )" );
        return true;

    }

    else
    {
        //account could not be added
        qDebug() << "Could not connect to database";
        return false;
    }

}

void CreateAccountPage::on_createButton_clicked()
{
    QString message = "";
    if(ui->firstNameInput->text().isEmpty()||ui->lastNameInput->text().isEmpty()|| ui->userNameInput->text().isEmpty()|| ui->passwordInput->text().isEmpty()||ui->retypePasswordInput->text().isEmpty())
    {
        message = "Field(s) cannot be left empty";
    }
    else
    {
        //see if the connection to the database was successful
        if(connectToAccountDB())
        {

            //get values from the form
            QString firstName = ui->firstNameInput->text();
            QString lastName = ui->lastNameInput->text();
            QString userName = ui->userNameInput->text();
            QString password = ui->passwordInput->text();
            QString retypePassword = ui->retypePasswordInput->text();

            //check if the username and password are valid
            if(!validUserName(userName))
            {
                message = "Username already exists\n";
            }

            else if(!validPassword(password))
            {
                message += "Password is not valid\n";
            }

            else if(password != retypePassword)
            {
                message += "Passwords do not match";
            }

            else
            {
                addAccount(userName, password, firstName, lastName, user);
                message = "Account has been successfully added.";
                //disable the create account button
                ui->createButton->setDisabled(true);

            }

            //close the database connection
            db.close();
            qDebug() << "Database has been closed";
        }


        //if we could not connect to the database
        else
        {
            //change message text
            message = "New account could not be added.";
        }

    }

    //call change text message
    ui->createAccountMessage->setText(message);
    ui->createAccountMessage->show();
}


void CreateAccountPage::addAccount(QString userName, QString password, QString firstName, QString lastName, AccountType accountType)
{


    /*FOR TESTING PURPOSES
    QJsonDocument jsonDoc(makeObjArray());
    QByteArray byteArray = jsonDoc.toJson(QJsonDocument::Compact);
    -------------------------------------------------------*/
    //put the values into the database
    QByteArray byteArray;
    //make a query
    QSqlQuery query = QSqlQuery(db);
    query.prepare("INSERT INTO account (userName, password, firstName, lastName, accountType, items) VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(userName);
    query.addBindValue(password);
    query.addBindValue(firstName);
    query.addBindValue(lastName);
    query.addBindValue(accountType);
    query.addBindValue(byteArray);


    //insert it into database
    query.exec();
}


bool CreateAccountPage::validUserName(QString userName)
{
    //check the database to see if the username exists
    QSqlQuery query = QSqlQuery(db);
    //query.prepare("SELECT userName from account WHERE fi");
    query.prepare("SELECT userName FROM account WHERE userName = ?");
    query.addBindValue(userName);

    query.exec();

    //a valid username is when the row does not exist
    return !query.first();
}

bool CreateAccountPage::validPassword(QString password)
{
    //use regex for password creation
    //password must between 8-16 characters and include at least 1 number, l capital letter, and one lower case letter
    //regex = ^(?=.*[0-9]+.*)(?=.*[a-z]+.*)(?=.*[A-Z]+.*){8,16}$
    QRegularExpression regEx("(?=.*[0-9]+.*)(?=.*[a-z]+.*)(?=.*[A-Z]+.*)[0-9a-zA-Z]{8,16}");
    int pos = 0;
    QRegularExpressionValidator valid(regEx);
    qDebug() << valid.validate(password, pos);
    //return valid.validate(password, pos);
    if(valid.validate(password, pos) == QValidator::Acceptable)
    {
        qDebug() << "valid password";
        return true;
    }

    else
    {
        qDebug() << "invalid password";
        return false;
    }

}

void CreateAccountPage::on_visiblePassword1_stateChanged(int state)
{
    //the visible password box is checked
    if(state == 2)
    {
      ui->passwordInput->setEchoMode(QLineEdit::Normal);
    }
    else
    {
      ui->passwordInput->setEchoMode(QLineEdit::Password);
    }
}

void CreateAccountPage::on_visiblePassword2_stateChanged(int state)
{
    //the visible password box is checked
    if(state == 2)
    {
      ui->retypePasswordInput->setEchoMode(QLineEdit::Normal);
    }
    else
    {
      ui->retypePasswordInput->setEchoMode(QLineEdit::Password);
    }
}


//FOR ITEM  INSERTING TESTING
QJsonArray CreateAccountPage::makeObjArray()
{
    QJsonArray array;
    QDate date = QDate::currentDate();
    //add 14 days to the checkout date
    date = date.addDays(14);
    //set time to 11:59 PM
    QTime time;
    time.setHMS(23, 59, 0);
    QDateTime dueDate;
    dueDate.setDate(date);
    dueDate.setTime(time);
    //QString dueDateStr = dueDate.toString(Qt::SystemLocaleLongDate);

    for (int i=0; i<10; i++)
    {
        QJsonObject obj;
        obj.insert("id", QJsonValue::fromVariant(2));
        obj.insert("quantity", QJsonValue::fromVariant(3));
        //obj.insert("dueDate", QJsonValue::fromVariant(dueDateStr));
        array.push_back(obj);
    }
    //qDebug() << array;

    return array;
}
