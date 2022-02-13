#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Tasker");
    QTableWidgetItem* item1 = new QTableWidgetItem();
    QTableWidgetItem* item2 = new QTableWidgetItem();
    item1->setText("Test11"); //работает
    item2->setText("Test12");
    ui->table->setItem(0,0,item1);
    ui->table->setItem(0,1,item2);
    //ui->table->update();
    add_form = new Add_form;
    QObject::connect(this, &MainWindow::sendShow, add_form, &Add_form::show);
   // QObject::connect(CancelButton, &QPushButton::clicked, Add, qOverload<>(&QWidget::hide));


}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AddButton_clicked()
{
    //if (NULL == add_form) add_form = new Add_form;
    emit sendShow();
    //add_form->show();

}

