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
    connect(mCounter,SIGNAL(signalTimeChange(QTime)),this,SLOT(onCountDownSec(QTime)));

    mTimer = new widgtimer(this);

    connect(ui->pushButton_tstart,SIGNAL(clicked(bool)),this,SLOT(onTimerStart()));
    connect(ui->pushButton_tstop,SIGNAL(clicked(bool)),mTimer,SLOT(onCounterStop()));
    connect(mTimer,SIGNAL(signalTimeChange(QTime)),this,SLOT(onTimerDownSec(QTime)));
    connect(mTimer,SIGNAL(signalTimeOut()),this,SLOT(onTimerTimeOut()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onTimerStart()
{
    mTimer->getTime(ui->timeEdit_2->time());
    mTimer->onCounterStart();
}

void Dialog::onTimerTimeOut()
{
    QMessageBox::information(this,"Time Out","Time Out!!");
}

void Dialog::onCountDownSec(QTime mtime)
{
    ui->timeEdit->setTime(mtime);
}

void Dialog::onTimerDownSec(QTime mtime)
{
    ui->timeEdit_2->setTime(mtime);
}

