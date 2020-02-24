#include "database.h"

database::database(QObject *parent) : QObject(parent)
{

}

//методы подключения к базе данных
void database::connectToDataBase()
{
    /*перед подключением к базе данных производим проверку на ее
     * существование.
     * в зависимости от результата производим открытие базы данных
     * или ее восстановление
    */
    if(!QFile("C:/PROJECT/QtCreator/aircraftAccounting/" DATABASE_NAME).exists())
        this->restoreDataBase();
    else this->openDataBase();
}

//методы восстановления базы данных
bool database::restoreDataBase()
{
    if(this->openDataBase()) {
        if(!this->createTable())
            return false;
        else
            return true;
    } else {
        qDebug() << "Не удалось восстановить базу данных";
         return false;
    }
    //return false;
}

//методы для открытия базы данных
bool database::openDataBase()
{
    //база данных открывается по заданному пути
    //и имени базы данных, если она существует
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName("C:/PROJECT/QtCreator/aircraftAccounting/" DATABASE_NAME);
    if(db.open())
        return true;
    else
        return false;
}

//методы закрытия базы данных
void database::closeDataBase()
{
    db.close();
}

//метод для создания базы данных
bool database::createTable()
{
    /*в данном случае используется формирование сырого  SQL-запроса
    с последующим его выполнением*/
    QSqlQuery query;
    if (!query.exec("CREATE TABLE " TABLE "("
                                            "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                                             TABLE_DATE         " DATE              NOT NULL, "
                                             TABLE_TIME         " TIME              NOT NULL, "
                                             TABLE_NUMBER  " STRING          NOT NULL, "
                                             TABLE_OUT           " STRING         NOT NULL, "
                                             TABLE_TO              " STRING         NOT NULL, "
                                             TABLE_PLACES      " INTEGER       NOT NULL, "
                                " )"
                    )) {
        qDebug() << "DataBase: error of create" << TABLE;
        qDebug() <<query.lastError().text();
        return false;
    } else
        return true;
    //return  false;
}

//метод для вставки записи в базу данных
bool database::insertIntoTable(const QVariantList &data)
{
    /*запрос SQL формируется  из QVariantList,
    в который передаются данные для вставки в таблицу*/
    QSqlQuery query;
    /*в начале SQL запрос формируется с ключами,
    которые потом связываются методом bindValue
    для подстановки данных из QVariantList*/
    query.prepare("INSERT INTO " TABLE " ( " TABLE_DATE ", "
                                                                              TABLE_TIME ", "
                                                                              TABLE_NUMBER ", "
                                                                              TABLE_OUT ", "
                                                                              TABLE_TO ", "
                                                                              TABLE_PLACES " ) "
                                    "VALUE (:departure_date, :departure_time, :flight_number, "
                                                   ":departure_city, :city_of_arrival, :number_of_free_places ) " );
    query.bindValue(":departure_date",               data[0].toDate());
    query.bindValue(":departure_time" ,              data[1].toTime());
    query.bindValue(":flight_number",                  data[2].toString());
    query.bindValue(":departure_city",                 data[3].toString());
    query.bindValue(":city_of_arrival",                  data[4].toString());
    query.bindValue(":number_of_free_places", data[5].toInt());
    //после чего выполняется запрос методом exec()
    if (!query.exec()) {
        qDebug() << "error insert into" << TABLE;
        qDebug() << query.lastError().text();
        return false;
     } else
        return true;
}
