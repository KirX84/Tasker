#include "add.h"
#include "ui_add.h"

// создать файл и записать задачу
Add::Add(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
}

Add::~Add()
{
    delete ui;
}
