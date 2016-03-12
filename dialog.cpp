#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    mCounter = new widgcounter(this);
    connect(ui->pushButton_start,SIGNAL(clicked(bool)),mCounter,SLOT(onCounterStart()));
    connect(ui->pushButton_stop,SIGNAL(clicked(bool)),mCounter,SLOT(onCounterStop()));
    connect(ui->pushButton_pause,SIGNAL(clicked(bool)),mCounter,SLOT(onCountPause()));
    connect(mCounter,SIGNAL(signalPlusSec(QTime)),this,SLOT(onCountDownSec(QTime)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onCountDownSec(QTime mtime)
{
    ui->timeEdit->setTime(mtime);
}

