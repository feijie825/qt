#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnIniItems_2_clicked();

    void on_btnClearItems_2_clicked();

    void on_btnIni2_2_clicked();

    void on_chkBoxEditable_2_clicked(bool checked);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_comboBox2_2_currentTextChanged(const QString &arg1);

    void on_btnToComboBox_2_clicked();

    void on_btnClearText_2_clicked();

    void on_chkBoxReadonly_2_clicked(bool checked);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
