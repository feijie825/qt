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


void Widget::on_btnCal_clicked()
{
    QString str=ui->editNum->text();	// 读取“数量”字符
    int num=str.toInt();	// 转换为Int
    str=ui->editPrice->text();
    float price=str.toInt();
    float total=num*price;
    str=str.asprintf("%.2f",total);	// 转换成字符串
    ui->editTotal->setText(str);	// 填充到LineEdit-total
}


void Widget::on_btnDec_clicked()
{
    QString str=ui->editDec->text();
    int val=str.toInt();

    str=str.setNum(val,16);	// 设置为16进制字符串
    str=str.toUpper();	// 设置成大写
    ui->editHex->setText(str);

    str=str.setNum(val,2);	// 将 val 转换成 2 进制字符串
    ui->editBin->setText(str);
}


void Widget::on_btnBin_clicked()
{
    QString str=ui->editBin->text();
    bool ok;	// 用于保存转换状态
    int val=str.toInt(&ok,2);
    str=QString::number(val,10);
    ui->editDec->setText(str);

    str=str.setNum(val,16);
    str=str.toUpper();
    ui->editHex->setText(str);
}


void Widget::on_btnHex_clicked()
{
    QString str=ui->editHex->text();
    bool ok;
    int val=str.toInt(&ok,16);

    str=str.asprintf("%d",val);
    ui->editDec->setText(str);

    str=str.setNum(val,2);
    ui->editBin->setText(str);
}

