#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QDebug>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Инициализируем второе окно
    windowAddingFlights = new addingflights();
    //подключаем к слоту запуска главного окна по кнопке во втором окне
    connect(windowAddingFlights, &addingflights::firstWindow, this,&MainWindow::show);
    // Инициализируем третье окно
    windowViewFlights = new viewflights();
     //подключаем к слоту запуска главного окна по кнопке в третьем окне
    connect(windowViewFlights,&viewflights::firstWindow,this,&MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnExit_clicked() {
    close();
}

void MainWindow::on_btnAddFlignt_clicked()
{
    windowAddingFlights->show();
    this->close();
}

void MainWindow::on_btnAvailableFlights_clicked()
{
    windowViewFlights->show();
    this->close();
}
