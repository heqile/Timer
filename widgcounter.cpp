#include "widgcounter.h"
#include <QDebug>

widgcounter::widgcounter(QObject *parent) : QObject(parent)
{
    mtimer = new timer(this);
    ss = mm = hh = 0;
    mtime = QTime::fromString("00:00:00","hh:mm:ss");
    connect(mtimer,SIGNAL(timeout()),this,SLOT(onCountDownSec()));
}

void widgcounter::onCounterStart()
{
    mtimer->start(1000);
}
void widgcounter::onCounterStop()
{
    mtimer->stop();
    ss = mm = hh = 0;
    mtime = QTime::fromString("00:00:00","hh:mm:ss");
    emit signalPlusSec(mtime);
}

void widgcounter::timeAccumu()
{
    ss++;
    if(ss == 60)
    {
        ss = 0;
        mm ++;
        if(mm == 60)
        {
            mm = 0;
            hh ++;
        }
    }
}

void widgcounter::onCountDownSec()
{
    timeAccumu();
    mtime = QTime::fromString(QString::number(hh)+":"+QString::number(mm)+":"+QString::number(ss),"h:m:s");
    emit signalPlusSec(mtime);
}

void widgcounter::onCountPause()
{
    mtimer->stop();
}

