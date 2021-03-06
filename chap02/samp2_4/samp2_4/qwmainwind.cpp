#include "qwmainwind.h"
#include "ui_qwmainwind.h"

QWMainWind::QWMainWind(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QWMainWind)
{
    ui->setupUi(this);
    iniUI();
    iniSignalSlots();
}

QWMainWind::~QWMainWind()
{
    delete ui;
}

void QWMainWind::iniUI()
{
    fLabCurFile=new QLabel;
    fLabCurFile->setMinimumWidth(150);
    fLabCurFile->setText("当前文件：");
    ui->statusbar->addWidget(fLabCurFile);

    progressBar1=new QProgressBar;
    progressBar1->setMaximumWidth(200);
    progressBar1->setMinimum(5);
    progressBar1->setValue(ui->txtEdit->font().pointSize());
    ui->statusbar->addWidget(progressBar1);

    spinFontSize=new QSpinBox;
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    spinFontSize->setValue(ui->txtEdit->font().pointSize());
    spinFontSize->setMinimumWidth(50);
    ui->mainToolBar->addWidget(new QLabel("字体大小："));
    ui->mainToolBar->addWidget(spinFontSize);

    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addWidget(new QLabel(" 字体 "));
    comboFont=new QFontComboBox;
    comboFont->setMinimumWidth(150);
    ui->mainToolBar->addWidget(comboFont);

    setCentralWidget(ui->txtEdit);
}

void QWMainWind::iniSignalSlots()
{
    connect(spinFontSize,SIGNAL(valueChanged(int)),this,SLOT(on_spinBoxFontSize_valueChanged(int)));
    connect(comboFont,SIGNAL(currentIndexChanged(const QString &)),this,SLOT(on_comboFont_currentIndexChanged(const QString &)));
}


void QWMainWind::on_actFontBold_toggled(bool checked)
{
    QTextCharFormat fmt;
    fmt=ui->txtEdit->currentCharFormat();
    if (checked)
        fmt.setFontWeight(QFont::Bold);
    else
        fmt.setFontWeight(QFont::Normal);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}
void QWMainWind::on_txtEdit_copyAvailable(bool b)
{
    ui->actCut->setEnabled(b);
    ui->actCopy->setEnabled(b);
    ui->actPaste->setEnabled(ui->txtEdit->canPaste());
}

void QWMainWind::on_txtEdit_selectionChanged()
{
    QTextCharFormat fmt;
    fmt=ui->txtEdit->currentCharFormat();
    ui->actFontItalic->setChecked(fmt.fontItalic());
    ui->actFontBold->setChecked(fmt.font().bold());
    ui->actFontUnder->setChecked(fmt.fontUnderline());
}

void QWMainWind::on_spinBoxFontSize_valueChanged(int aFontSize)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(aFontSize);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
    progressBar1->setValue(aFontSize);
}

void QWMainWind::on_comboFont_currentIndexChanged(const QString &arg1)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(arg1);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}
