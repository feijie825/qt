#include "widget.h"
#include "ui_widget.h"
#include <QColor>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QObject::connect(ui->SliderGreen,SIGNAL(valueChanged(int)),this,SLOT(on_SliderRed_valueChanged(int)));
    QObject::connect(ui->SliderBlue,SIGNAL(valueChanged(int)),this,SLOT(on_SliderRed_valueChanged(int)));
    QObject::connect(ui->SliderAlpha,SIGNAL(valueChanged(int)),this,SLOT(on_SliderRed_valueChanged(int)));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_SliderRed_valueChanged(int value)
{
    Q_UNUSED(value);
    QColor color;
    int R=ui->SliderRed->value();
    int G=ui->SliderGreen->value();
    int B=ui->SliderBlue->value();
    int A=ui->SliderAlpha->value();
    color.setRgb(R,G,B,A);

    QPalette pal=ui->textEdit->palette();
    // TODO:-> 与 . 区别?
    /* C++中::和:， .和->的作用和区别? - 知乎	2022/2/19 15:19:58
     * A.B则A为对象或者结构体； 点号（.）：左边必须为实体。
     *  A->B则A为指针，->是成员提取，A->B是提取A中的成员B，A只能是指向类、结构、联合的指针；
     *  箭头（->）：左边必须为指针；
     */
    pal.setColor(QPalette::Base,color);
    ui->textEdit->setPalette(pal);
}


void Widget::on_SliderH_valueChanged(int value)
{
    ui->ScrollBarH->setValue(value);
    ui->progBarH->setValue(value);
}


void Widget::on_SliderV_valueChanged(int value)
{
    ui->ScrollBarV->setValue(value);
    ui->progBarV->setValue(value);
}


void Widget::on_dial_valueChanged(int value)
{
    ui->LCDDisplay->display(value);
}


void Widget::on_radioBtnDec_clicked()
{
    ui->LCDDisplay->setDigitCount(3);
    ui->LCDDisplay->setDecMode();
}


void Widget::on_radioBtnBin_clicked()
{
    ui->LCDDisplay->setDigitCount(8);
    ui->LCDDisplay->setBinMode();
}


void Widget::on_radioBtnOct_clicked()
{
    ui->LCDDisplay->setDigitCount(4);
    ui->LCDDisplay->setOctMode();
}


void Widget::on_radioBtnHex_clicked()
{
    ui->LCDDisplay->setDigitCount(3);
    ui->LCDDisplay->setHexMode();
}


void Widget::on_ScrollBarH_sliderMoved(int position)
{
    ui->progBarH->setValue(position);
}


void Widget::on_ScrollBarV_sliderMoved(int position)
{
    ui->progBarV->setValue(position);
}

