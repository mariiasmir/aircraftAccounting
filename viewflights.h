#ifndef VIEWFLIGHTS_H
#define VIEWFLIGHTS_H

#include <QMainWindow>

namespace Ui {
class viewflights;
}

class viewflights : public QMainWindow
{
    Q_OBJECT

public:
    explicit viewflights(QWidget *parent = nullptr);
    ~viewflights();

private:
    Ui::viewflights *ui;
};

#endif // VIEWFLIGHTS_H
