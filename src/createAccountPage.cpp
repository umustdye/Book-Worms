#include "createAccountPage.h"
#include "ui_createAccountPage.h"

#include <QtSql>
#include <QString>
#include <QDebug>
#include <QRegExp>
#include <QRegExpValidator>

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
        query.exec( "CREATE TABLE IF NOT EXISTS account ( id INTEGER PRIMARY KEY AUTOINCREMENT, userName TEXT, password TEXT, firstName TEXT, lastName TEXT, accountType INTEGER )" );
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
    //put the values into the database

    //make a query
    QSqlQuery query = QSqlQuery(db);
    query.prepare("INSERT INTO account (userName, password, firstName, lastName, accountType) VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(userName);
    query.addBindValue(password);
    query.addBindValue(firstName);
    query.addBindValue(lastName);
    query.addBindValue(accountType);


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
