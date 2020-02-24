#include "addingflights.h"
#include "ui_addingflights.h"

addingflights::addingflights(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addingflights)
{
    ui->setupUi(this);
}

addingflights::~addingflights()
{
    delete ui;
}

void addingflights::on_btnComeBack_clicked()
{
    this->close();
    emit firstWindow();
}
