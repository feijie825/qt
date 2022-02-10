#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 数量和单价改变与计算槽关联
    QObject::connect(ui->spinNum,SIGNAL(valueChanged(int)),this,SLOT(on_btnCal_clicked()));
    QObject::connect(ui->spinPrice,SIGNAL(valueChanged(double)),this,SLOT(on_btnCal_clicked()));

    QObject::connect(ui->spinDec,SIGNAL(valueChanged(int)),this,SLOT(on_btnDec_clicked())); // 十进制
    QObject::connect(ui->spinBin,SIGNAL(valueChanged(int)),this,SLOT(on_btnBin_clicked()));	// 二进制
    QObject::connect(ui->spinHex,SIGNAL(valueChanged(int)),this,SLOT(on_btnHex_clicked()));	// 十六进制
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnCal_clicked()
{
    int num =ui->spinNum->value();
    float price=ui->spinPrice->value();
    float total=num*price;
    ui->spinTotal->setValue(total);
}


void Widget::on_btnDec_clicked()
{
   int val = ui->spinDec->value();
   ui->spinBin->setValue(val);
   ui->spinHex->setValue(val);
}


void Widget::on_btnBin_clicked()
{
   int val = ui->spinBin->value();
   ui->spinDec->setValue(val);
   ui->spinHex->setValue(val);
}


void Widget::on_btnHex_clicked()
{
   int val = ui->spinHex->value();
   ui->spinBin->setValue(val);
   ui->spinDec->setValue(val);
}

