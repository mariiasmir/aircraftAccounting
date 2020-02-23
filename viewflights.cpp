#include "viewflights.h"
#include "ui_viewflights.h"

viewflights::viewflights(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewflights)
{
    ui->setupUi(this);
}

viewflights::~viewflights()
{
    delete ui;
}
