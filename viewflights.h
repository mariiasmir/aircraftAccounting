#ifndef VIEWFLIGHTS_H
#define VIEWFLIGHTS_H

#include <QMainWindow>
#include <QSqlTableModel>
//подключаем заголовочный файл для работы с информацией, которая помещена в БД
#include "database.h"

namespace Ui {
class viewflights;
}

class viewflights : public QMainWindow
{
    Q_OBJECT

public:
    explicit viewflights(QWidget *parent = nullptr);
    ~viewflights();

signals:
    void firstWindow();

private slots:
    void on_btnComeBack_clicked();

private:
    Ui::viewflights *ui;

    //используем объекты для взаимодействия с информацией в базе данных
    //и моделью представления таблицы базы данных
    database *db;
    QSqlTableModel *model;
    //добавляем два метода, которые формируют модель
    //и внешний вид TableView
    void setupModel(const QString &tableName, const QStringList &headers);
    void createUI();
};

#endif // VIEWFLIGHTS_H
