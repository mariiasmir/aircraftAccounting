#ifndef ADDINGFLIGHTS_H
#define ADDINGFLIGHTS_H

#include <QMainWindow>

namespace Ui {
class addingflights;
}

class addingflights : public QMainWindow
{
    Q_OBJECT

public:
    explicit addingflights(QWidget *parent = nullptr);
    ~addingflights();

signals:
    void firstWindow();

private slots:
    void on_btnComeBack_clicked();

private:
    Ui::addingflights *ui;
};

#endif // ADDINGFLIGHTS_H
