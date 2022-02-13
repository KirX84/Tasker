#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add.cpp"

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
    ui->table->update();
    //ui->pushButton->      //появление формы Add

}

MainWindow::~MainWindow()
{
    delete ui;
}

