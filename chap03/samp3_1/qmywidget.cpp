#include "qmywidget.h"
#include "ui_qmywidget.h"
//#include "qperson.h"
#include <QMetaProperty>

QmyWidget::QmyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QmyWidget)
{
    ui->setupUi(this);
    boy=new QPerson("王小明");
    boy->setProperty("score",95);	// 动态属性？否 为什么要使用这种方式？为什么不是m_score? m_score 是成员变量，score 是 Q_PROPERTY 属性
    boy->setProperty("age",10);
    boy->setProperty("sex","Boy");	// 动态属性
    connect(boy,&QPerson::ageChanged,this,&QmyWidget::on_ageChanged);	// 为什么函数后不能添加括号

    girl=new QPerson("张小丽");
    girl->setProperty("score",81);
    girl->setProperty("age",20);
    girl->setProperty("sex","Girl");	// 动态属性
    connect(girl,&QPerson::ageChanged,this,&QmyWidget::on_ageChanged);

    ui->spinBoy->setProperty("isBoy",true);
    ui->spinGirl->setProperty("isBoy",false);

    connect(ui->spinGirl,SIGNAL(valueChanged(int)),
            this,SLOT(on_spin_valueChanged(int)));
    connect(ui->spinBoy,SIGNAL(valueChanged(int)),
            this,SLOT(on_spin_valueChanged(int)));
}

QmyWidget::~QmyWidget()
{
    delete ui;
}

void QmyWidget::on_ageChanged(int value)
{
    // 响应 QPerson 的 ageChanged() 信号
    Q_UNUSED(value);	// ?
    QPerson *aPerson=qobject_cast<QPerson *>(sender());	// 类型投射
    QString hisName=aPerson->property("name").toString();	// 姓名
    QString hisSex=aPerson->property("sex").toString();	// 动态属性
    int hisAge=aPerson->age();	// 通过接口函数获取年龄
//    int hisAge=aPerson->property("age"),toInt();	// 通过属性获得年龄
    ui->textEdit->appendPlainText(hisName+","+hisSex
                                  +QString::asprintf(",年龄=%d",hisAge));
}

void QmyWidget::on_spin_valueChanged(int arg1)
{
    // 响应界面上 spinBox 的 valueChanged(int) 信号
    Q_UNUSED(arg1);
    QSpinBox *spinBox=qobject_cast<QSpinBox *>(sender());
    if(spinBox->property("isBoy").toBool())
        boy->setAge(spinBox->value());
    else
        girl->setAge(spinBox->value());
}

void QmyWidget::on_btnClear_clicked()
{
    ui->textEdit->clear();
}

void QmyWidget::on_btnBoyInc_clicked()
{
    boy->incAge();
}

void QmyWidget::on_btnGirlInc_clicked()
{
    girl->incAge();
}

void QmyWidget::on_btnClassInfo_clicked()
{
    // “类的元对象信息”按钮
    const QMetaObject *meta=boy->metaObject();
    ui->textEdit->clear();
    ui->textEdit->appendPlainText("==元对象信息==\n");
    ui->textEdit->appendPlainText(
                QString("类名称：%1\n").arg(meta->className()));
    ui->textEdit->appendPlainText("property");
    for(int i=meta->propertyOffset();i<meta->propertyCount();i++)
    {
        QMetaProperty prop=meta->property(i);
        const char* propName=prop.name();
        QString propValue=boy->property(propName).toString();
        ui->textEdit->appendPlainText(
                    QString("属性名称=%1, 属性值=%2").arg(propName).arg(propValue));
    }

    ui->textEdit->appendPlainText("");
    ui->textEdit->appendPlainText("classInfo");
    for (int i=meta->classInfoOffset();i<meta->classInfoCount();++i)
    {
        QMetaClassInfo classInfo=meta->classInfo(i);
        ui->textEdit->appendPlainText(QString("Name=%1; Value=%2")
                                      .arg(classInfo.name()).arg(classInfo.value()));
    }
}

