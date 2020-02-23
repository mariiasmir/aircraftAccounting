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
