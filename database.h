#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFile>
#include <QDebug>
#include <QDate>

//директивы имен таблицы, полей таблицы и базы данных
#define DATABASE_HOSTNAME   "DataBase"
#define DATABASE_NAME             "db.db"

#define TABLE                                  "available_flights"
#define TABLE_DATE                       "departure_date"
#define TABLE_TIME                       "departure_time"
#define TABLE_NUMBER                "flight_number"
#define TABLE_OUT                        "departure_city"
#define TABLE_TO                           "city_of_arrival"
#define TABLE_PLACES                   "number_of_free_places"

 class database : public QObject
{
    Q_OBJECT
public:
    explicit database(QObject *parent = nullptr);

    //методы для непосредственной работы с классом
    // подключение к базе данных и вставка записей в таблицу
    void connectToDataBase();
    bool insertIntoTable(const QVariantList &data);

private:
    //сам объект базы данных, с которым будет производится работа
    QSqlDatabase db;
    //внутренние методы для работы с БД
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createTable();

};

#endif // DATABASE_H
