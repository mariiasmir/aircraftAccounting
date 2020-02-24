#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//подключаем заголовочные файлы с двух новых окон
#include "addingflights.h"
#include "viewflights.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnExit_clicked();

    void on_btnAddFlignt_clicked();

    void on_btnAvailableFlights_clicked();

private:
    Ui::MainWindow *ui;
    //объекты двух других окон
    addingflights *windowAddingFlights;
    viewflights *windowViewFlights;
};

#endif // MAINWINDOW_H
