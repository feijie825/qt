#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
   QString str1=ui->comboBox->currentText();
   QString str2=ui->comboBox_2->currentText();
   QString str3=str1.append(str2);
   ui->edtResult->setText(str3);
}


void Widget::on_pushButton_2_clicked()
{
   QString str1=ui->comboBox->currentText();
   QString str2=ui->comboBox_2->currentText();
   QString str3=str2.append(str1);
   ui->edtResult->setText(str3);
}


void Widget::on_pushButton_3_clicked()
{
    QString str=ui->comboBox->currentText();
    str=str.toUpper();
    ui->edtResult->setText(str);
}


void Widget::on_pushButton_4_clicked()
{
    QString str=ui->comboBox->currentText();
    str=str.toLower();
    ui->edtResult->setText(str);
}


void Widget::on_pushButton_5_clicked()
{
    QString str1,str2;
    str1=ui->comboBox->currentText();
    int v=ui->spinBox->value();
    str2=str1.left(v);
    ui->edtResult->setText(str2);
}


void Widget::on_pushButton_6_clicked()
{
    QString str1,str2;
    str1=ui->comboBox->currentText();
    int cnt=str1.size();
    int v=ui->spinBox->value();
    str2=str1.right(cnt-v-1);
    ui->edtResult->setText(str2);
}


void Widget::on_pushButton_7_clicked()
{
    QString str1,str2,str3;
    str1=ui->comboBox->currentText();
    str2=ui->comboBox_2->currentText();
    int v=ui->spinBox->value();
    if (QString::compare(str2,"\\",Qt::CaseInsensitive)==0)
        str3=str1.section("\\",v,v+1);
    else
        str3=str1.section(str2,v,v+1);
    ui->edtResult->setText(str3);
}


void Widget::on_pushButton_8_clicked()
{
    QString str1;
    str1=ui->comboBox->currentText();
    str1=str1.simplified();
    ui->edtResult->setText(str1);
}


void Widget::on_pushButton_9_clicked()
{
    QString str1;
    str1=ui->comboBox->currentText();
    str1=str1.trimmed();
    ui->edtResult->setText(str1);
}


void Widget::on_pushButton_10_clicked()
{
    QString str1;
    str1=ui->comboBox->currentText();
    str1=QString::number(str1.count());
    ui->edtResult->setText(str1);
}


void Widget::on_pushButton_12_clicked()
{
    QString str1,str2;
    str1=ui->comboBox->currentText();
    str2=ui->comboBox_2->currentText();
    bool chk=str1.indexOf(str2);
    ui->checkBox->setChecked(chk);
    ui->checkBox->setText("indexOf()");
    ui->checkBox->sizeHint();
}

