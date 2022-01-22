#ifndef QWMAINWIND_H
#define QWMAINWIND_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QSpinBox>
#include <QFontComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class QWMainWind; }
QT_END_NAMESPACE

class QWMainWind : public QMainWindow
{
    Q_OBJECT

public:
    QWMainWind(QWidget *parent = nullptr);
    ~QWMainWind();

private slots:
    void on_actFontBold_toggled(bool arg1);

    void on_txtEdit_copyAvailable(bool b);

    void on_txtEdit_selectionChanged();

    void on_spinBoxFontSize_valueChanged(int aFontSize);
    void on_comboFont_currentIndexChanged(const QString &arg1);

private:
    Ui::QWMainWind *ui;
    QLabel *fLabCurFile;
    QProgressBar *progressBar1;
    QSpinBox *spinFontSize;
    QFontComboBox *comboFont;
    void iniUI();
    void iniSignalSlots();
};
#endif // QWMAINWIND_H
