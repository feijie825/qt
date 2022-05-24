#include "widget.h"
#include "ui_widget.h"

#include <QDateTime>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    fTimer=new QTimer(this);
    fTimer->stop();
    fTimer->setInterval(1000);	//设置定时周期，单位毫秒
    connect(fTimer,SIGNAL(timeout()),this,SLOT(on_timer_timeout()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnGetTime_clicked()
{
   QDateTime curDateTime=QDateTime::currentDateTime();

   ui->timeEdit->setTime(curDateTime.time());
   ui->editTime->setText(curDateTime.toString("hh:mm:ss"));
   ui->dateEdit->setDate(curDateTime.date());
   ui->editDate->setText(curDateTime.toString("yyyy-MM-dd"));
   ui->dateTimeEdit->setDateTime(curDateTime);
   ui->editDateTime->setText(curDateTime.toString("yyyy-MM-dd hh:mm:ss"));
}


void Widget::on_btnSetTime_clicked()
{
   QString str=ui->editTime->text();

   if(!str.isEmpty())
   {
       QTime tm=QTime::fromString(str,"hh:mm:ss");
       ui->timeEdit->setTime(tm);
   }
}


void Widget::on_btnSetDate_clicked()
{
    QString str=ui->editDate->text();

    if(!str.isEmpty())
    {
        QDate dt=QDate::fromString(str,"yyyy-MM-dd");
        ui->dateEdit->setDate(dt);
    }
}


void Widget::on_calendarWidget_selectionChanged()
{
    QDate curDate=ui->calendarWidget->selectedDate();

    ui->editCalendar->setText(curDate.toString("yyyy年MM月dd日"));
}

void Widget::on_timer_timeout()
{
    QTime curTime=QTime::currentTime();	//获取当前时间
    ui->LCDHour->display(curTime.hour());	//显示 小时
    ui->LCDMin->display(curTime.minute());	//显示 分钟
    ui->LCDSec->display(curTime.second());	//显示 秒
    int va=ui->progressBar->value();
    va++;
    if(va>100)
        va=0;
    ui->progressBar->setValue(va);
}


void Widget::on_btnStart_clicked()
{
    fTimer->start();	// 定时器开始工作
    fTimeCounter.start();	//计时器开始工作
    ui->btnStart->setEnabled(false);
    ui->btnStop->setEnabled(true);
    ui->btnSetIntv->setEnabled(false);
}


void Widget::on_btnStop_clicked()
{
    fTimer->stop();	//定时器停止
    int tmMsc=fTimeCounter.elapsed();
    int ms=tmMsc%1000;
    int sec=tmMsc/1000;
    QString str=QString::asprintf("流逝时间：%d 秒，%d 毫秒",sec,ms);
    ui->LabElapsTime->setText(str);
    ui->btnStart->setEnabled(true);
    ui->btnStop->setEnabled(false);
    ui->btnSetIntv->setEnabled(true);
}


void Widget::on_btnSetIntv_clicked()
{
    fTimer->setInterval(ui->spinBoxIntv->value());
}

