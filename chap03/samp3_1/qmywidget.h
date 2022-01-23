#ifndef QMYWIDGET_H
#define QMYWIDGET_H

#include <QWidget>
#include "qperson.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QmyWidget; }
QT_END_NAMESPACE

class QmyWidget : public QWidget
{
    Q_OBJECT

private:
    QPerson *boy;
    QPerson *girl;
public:
    explicit QmyWidget(QWidget *parent = 0);	// ? *parent 作用
    ~QmyWidget();

private:
    Ui::QmyWidget *ui;
private slots:
    // 自定义槽函数
    void on_ageChanged(int value);
    void on_spin_valueChanged(int arg1);
    // 界面按钮槽函数
    void on_btnClear_clicked();
    void on_btnBoyInc_clicked();
    void on_btnGirlInc_clicked();
    void on_btnClassInfo_clicked();
};
#endif // QMYWIDGET_H
