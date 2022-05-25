#include "widget.h"
#include "ui_widget.h"

#include <QString>
#include <QTextDocument>
#include <QTextBlock>
#include <QMenu>
#include <QMap>
#include <QVariant>

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


void Widget::on_btnIniItems_2_clicked()
{
    QIcon icon;
    icon.addFile(":/images/icons/aim.ico");

    ui->comboBox_2->clear();
    for(int i=0;i<20;i++)
        ui->comboBox_2->addItem(icon,QString::asprintf("Item %d",i)); // 带图标
}


void Widget::on_btnClearItems_2_clicked()
{
    ui->comboBox_2->clear();
}


void Widget::on_btnIni2_2_clicked()
{
    QMap<QString,int> City_Zone;
    City_Zone.insert("北京",10);
    City_Zone.insert("上海",21);
    City_Zone.insert("天津",22);
    City_Zone.insert("大连",411);
    City_Zone.insert("锦州",416);
    City_Zone.insert("徐州",516);
    City_Zone.insert("福州",591);
    City_Zone.insert("青岛",532);
    ui->comboBox2_2->clear();
    foreach(const QString &str,City_Zone.keys())
        ui->comboBox2_2->addItem(str,City_Zone.value(str));
//    foreach(auto val,City_Zone.values())
//        ui->comboBox2_2->addItem(QString::number(val));
}


void Widget::on_chkBoxEditable_2_clicked(bool checked)
{
    ui->comboBox_2->setEditable(checked);
}


void Widget::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    ui->plainTextEdit_2->appendPlainText(arg1);
}


void Widget::on_comboBox2_2_currentTextChanged(const QString &arg1)
{
    QString zone=ui->comboBox2_2->currentData().toString();
    ui->plainTextEdit_2->appendPlainText(arg1+":区号="+zone);
}


void Widget::on_btnToComboBox_2_clicked()
{
    QTextDocument* doc=ui->plainTextEdit_2->document();
    int cnt=doc->blockCount();
    QIcon icon(":/images/icons/aim.ico");
    ui->comboBox_2->clear();
    for(int i=0;i<cnt;i++)
    {
        QTextBlock textLine=doc->findBlockByNumber(i);
        QString str=textLine.text();
        ui->comboBox_2->addItem(icon,str);
    }
}


void Widget::on_btnClearText_2_clicked()
{
    ui->plainTextEdit_2->clear();
}


void Widget::on_chkBoxReadonly_2_clicked(bool checked)
{
    ui->plainTextEdit_2->setReadOnly(checked);
}

