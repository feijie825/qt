#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>
void MainWindow::setActionsForButton()
{
    ui->tBtnListIni->setDefaultAction(ui->actListIni);
    ui->tBtnListClear->setDefaultAction(ui->actListClear);
    ui->tBtnListInsert->setDefaultAction(ui->actListInsert);
    ui->tBtnListAppend->setDefaultAction(ui->actListAppend);
    ui->tBtnListDelete->setDefaultAction(ui->actListDelete);

    ui->tBtnSelAll->setDefaultAction(ui->actSelALL);
    ui->tBtnSelNone->setDefaultAction(ui->actSelNone);
    ui->tBtnSelInvs->setDefaultAction(ui->actSelInvs);
}

void MainWindow::createSelectionPopMenu()
{
    // 创建下拉菜单
    QMenu *menuSelection=new QMenu(this);
    menuSelection->addAction(ui->actSelALL);
    menuSelection->addAction(ui->actSelNone);
    menuSelection->addAction(ui->actSelInvs);

    // list 上方 tBtnSelectItem 按钮
    ui->tBtnSelectItem->setPopupMode(QToolButton::MenuButtonPopup);
    ui->tBtnSelectItem->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tBtnSelectItem->setDefaultAction(ui->actSelPopMenu);	// 关联action
    ui->tBtnSelectItem->setMenu(menuSelection);	// 设置下拉菜单
    // 工具栏上的下拉式菜单按钮
    QToolButton *aBtn=new QToolButton(this);
    aBtn->setPopupMode(QToolButton::InstantPopup);
    aBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    aBtn->setDefaultAction(ui->actSelPopMenu);
    aBtn->setMenu(menuSelection);
    ui->mainToolBar->addWidget(aBtn);

    ui->mainToolBar->addSeparator();
    ui->mainToolBar->addAction(ui->actQuit);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->splitter);
    setActionsForButton();
    createSelectionPopMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actListIni_triggered()
{
    // 初始化列表
    QListWidgetItem *aItem;
    QIcon aIcon;

    aIcon.addFile(":/images/icons/check2.ico");
    bool chk=ui->chkBoxListEditable->isChecked();	// 是否可编辑

    ui->listWidget->clear();
    for (int i=0;i<10;i++)
    {
        QString str=QString::asprintf("Item %d",i);
        aItem=new QListWidgetItem();
        aItem->setText(str);	// 设置文字标签
        aItem->setIcon(aIcon);	// 设置图标
        aItem->setCheckState(Qt::Checked);	// 设置为选中状态
        if (chk)	// 可编辑，设置flags
            aItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable
                            |Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        else	// 不可编辑，设置false
            aItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable
                            |Qt::ItemIsEnabled);
        ui->listWidget->addItem(aItem);	// 增加一个项
    }
}


void MainWindow::on_actListInsert_triggered()
{
    QListWidgetItem *aItem;
    QIcon aIcon;

    aIcon.addFile(":/images/icons/check2.ico");
    bool chk=ui->chkBoxListEditable->isChecked();

    aItem=new QListWidgetItem("New Inserted Item");
    aItem->setIcon(aIcon);
    aItem->setCheckState(Qt::Checked);
    if (chk)	// 可编辑，设置flags
        aItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable
                |Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
    else	// 不可编辑，设置false
        aItem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable
                |Qt::ItemIsEnabled);
    ui->listWidget->insertItem(ui->listWidget->currentRow(),aItem);
}


void MainWindow::on_actListDelete_triggered()
{
    int row=ui->listWidget->currentRow();
    QListWidgetItem *aItem=ui->listWidget->takeItem(row);
    delete aItem;
}


void MainWindow::on_actListClear_triggered()
{
    ui->listWidget->clear();
}


void MainWindow::on_actSelALL_triggered()
{
    int cnt=ui->listWidget->count();

    for(int i=0;i<cnt;i++)
    {
        QListWidgetItem *aItem=ui->listWidget->item(i);
        aItem->setCheckState(Qt::Checked);
    }
}


void MainWindow::on_actSelNone_triggered()
{
    int cnt=ui->listWidget->count();

    for(int i=0;i<cnt;i++)
    {
        QListWidgetItem *aItem=ui->listWidget->item(i);
        aItem->setCheckState(Qt::Unchecked);
    }
}


void MainWindow::on_actSelInvs_triggered()
{
    int cnt=ui->listWidget->count();
    QListWidgetItem *aItem;

    for(int i=0;i<cnt;i++)
    {
        aItem=ui->listWidget->item(i);
        if(aItem->checkState()!=Qt::Checked)
            aItem->setCheckState(Qt::Checked);
        else
            aItem->setCheckState(Qt::Unchecked);
    }
}


void MainWindow::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    QString str;
    if(current!=NULL)
    {
        if (previous==NULL)
            str="当前项： "+current->text();
        else
            str="前一项： "+previous->text()+"; 当前项： "+current->text();
        ui->editCutItemText->setText(str);
    }
}


void MainWindow::on_listWidget_customContextMenuRequested(const QPoint &pos)
{
    Q_UNUSED(pos);
    QMenu* menuList=new QMenu(this);	// 创建菜单
    // 添加 Actions 创建菜单项
    menuList->addAction(ui->actListIni);
    menuList->addAction(ui->actListClear);
    menuList->addAction(ui->actListInsert);
    menuList->addAction(ui->actListAppend);
    menuList->addAction(ui->actListDelete);
    menuList->addSeparator();
    menuList->addAction(ui->actSelALL);
    menuList->addAction(ui->actSelNone);
    menuList->addAction(ui->actSelInvs);
    menuList->exec(QCursor::pos());	// 在鼠标光标位置显示右键快捷菜单
    delete menuList;
}
