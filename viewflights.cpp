#include "viewflights.h"
#include "ui_viewflights.h"

viewflights::viewflights(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::viewflights)
{
    ui->setupUi(this);

    //создаем объект, который будет использоваться для работы с БД
    //и инициализировать подключение к БД
    db = new database();
    db->connectToDataBase();

    //инициализируем модель для представления
    //данных с задание названия колонок
    this->setupModel(TABLE,
                                    QStringList() << tr("ID")
                                                           << tr("Дата вылета")
                                                           << tr("Время вылета")
                                                           << tr("Номер рейса")
                                                           << tr("Город вылета")
                                                           << tr("Город прибытия")
                                                           << tr("Количество свободных мест"));

    //инициализируем внешний вид таблицы с данными
    this->createUI();
}

viewflights::~viewflights()
{
    delete ui;
}

void viewflights::on_btnComeBack_clicked()
{
    this->close();
    emit firstWindow();
}

void viewflights::setupModel(const QString &tableName, const QStringList &headers)
{
    /*производим инициализацию модели представления данных
     *с установной имени таблицы в базе данных, по которому
     * будет производится обращение в таблице
    */
    model = new QSqlTableModel(this);
    model->setTable(tableName);
    //устанавливаем название колонок в таблице с
    //сортировкой данных
    for (int i = 0, j=0; i<model->columnCount(); i++, j++)
        model->setHeaderData(i,Qt::Horizontal,headers[j]);
    //устанавливаем сортировку по возрастанию данных
    //по нулей колонке
    model->setSort(0,Qt::AscendingOrder);
}

void viewflights::createUI()
{
    ui->dataBaseView->setModel(model); //устанавливаем модель на tableview
    ui->dataBaseView->setColumnHidden(0, true);//скрываем колонку с ID записей
    //разрешаем выделение строк
    ui->dataBaseView->setSelectionBehavior(QAbstractItemView::SelectRows);
    //устанавливаем режим выделения лишь одной строки в таблице
    ui->dataBaseView->setSelectionMode(QAbstractItemView::SingleSelection);
    //утсанавливаем размер колонок по содержимому
    ui->dataBaseView->resizeColumnsToContents();
    ui->dataBaseView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->dataBaseView->horizontalHeader()->setStretchLastSection(true);

    model->select(); //делаем выборку данных из таблицы
}
