#ifndef ADD_FORM_H
#define ADD_FORM_H

#include <QFile>
#include <QWidget>
#include <QTextStream>

namespace Ui {
class Add_form;
}

class Add_form : public QWidget
{
    Q_OBJECT

public:
    explicit Add_form(QWidget *parent = nullptr);
    ~Add_form();
    void close();
    void XML_db(QString, QDate, QTime);
    void AddRec(QString, QDate, QTime, QFile*);
    bool check_mask(QString, QString);
    bool is_num(QString*);
    bool testb();

signals:

private slots:
    void on_saveButton_clicked();

    void on_CancelButton_clicked();

private:
    Ui::Add_form *ui;
};

#endif // ADD_FORM_H
