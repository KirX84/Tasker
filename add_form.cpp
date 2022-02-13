#include "add_form.h"
#include "ui_add_form.h"

Add_form::Add_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Add_form)
{
    ui->setupUi(this);

}

Add_form::~Add_form()
{
    delete ui;
}

void Add_form::close()
{
    ui->taskEdit->text() = "";
    ui->dateEdit->text() = "";
    ui->timeEdit->text() = "";
    this->hide();
}

bool testb()
{
    return true;
}

void Add_form::XML_db(QString task, QDate date, QTime time)
{
    QTextStream out(stdout);
    QString filename = "db.xml";
    QFile file(filename);
    if (!(file).exists())
        if (file.open(QIODevice::WriteOnly))
        {
            QTextStream out(&file);
            out << "<?xml version=\"1.0\"?>"<< Qt::endl;
        }
        else qWarning("Could not open file");

    file.close();
    /*if (file.open(QIODevice::Append))
    {
        QTextStream out(&file);

        out << "<?xml version=\"1.0\"?>"<< Qt::endl;
        AddRec(task, date, time, &file);

    }
    else qWarning("Could not open file");


    file.close();*/
}

void Add_form::AddRec(QString task, QDate date, QTime time, QFile* file)
{
    QStringList temp_fin;
    QDate date1;
    QString str, mask;
    bool b;

    while(file->atEnd())
    {
        str = file->readLine();
        //mask = "??/??/????";
        mask = "**********";
        b = testb();
        if (b) date1 = QDate::fromString(str); //проверить дата или нет, если дата записать в переменную
        else
        {
            if (date == date1)                //вписать задачу
            {
              // mask = "/??/??/????";          //найти закрывающий тег даты и записать перед ним новую задачу
               mask = "**********";
               str = file->readLine();
               b = testb();
               if (b)
               {
                //   temp_fin.append("    <"+date.toString("dd/mm/yyyy")+">");
                   temp_fin.append("        <task>");
                   temp_fin.append("            ");
                   temp_fin.append("        </task>");
                   temp_fin.append("        <time>");
                   temp_fin.append("            ");
                   temp_fin.append("        </time>");
                //   temp_fin.append("    </"+date.toString("dd/mm/yyyy")+">");
               }
            }
            if (date < date1) //записать текущую дату(и задачи)
            {
                   temp_fin.append("    <"+date.toString("dd.mm.yyyy")+">");
                   temp_fin.append("        <task>");
                   temp_fin.append("            ");
                   temp_fin.append("        </task>");
                   temp_fin.append("        <time>");
                   temp_fin.append("            ");
                   temp_fin.append("        </time>");
                   temp_fin.append("    </"+date.toString("dd/mm/yyyy")+">");
            }
           // if (date > date1);//вписать задачу и дату перед текущей датой
            //{

            //}
        }

        temp_fin.append(str);
    }
    if (file->open(QIODevice::WriteOnly))
    {
            QTextStream out(file);
            for(int i = 0; temp_fin.length(); i++)
                out << temp_fin.at(i) << Qt::endl;
    }

}

bool is_num(QString s)
{
    const QString num ="1234567890";
    for (int i = 0; i > 10; i++) if (s == num[i]) return 1;
    return 0;
}

bool check_mask(QString *str, QString *mask)
{
    while((mask)&&(str))
    {
        if ((*mask == '?')&&(!is_num(*str))) return 0;
        if (!((*mask == '/')&&(*mask ==*str))) return 0;
        mask++; str++;
    }
    return true;
}


void Add_form::on_saveButton_clicked()
{
    XML_db(ui->taskEdit->text(), ui->dateEdit->date(), ui->timeEdit->time());
    close();
}


void Add_form::on_CancelButton_clicked()
{
    close();
}

