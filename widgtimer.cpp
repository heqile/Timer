#include "widgtimer.h"
#include <QDebug>

widgtimer::widgtimer(QObject *parent) : QObject(parent)
{
    mtimer = new timer(this);
    hh = mm = ss = 0;
    connect(mtimer,SIGNAL(timeout()),this,SLOT(onCountDownSec()));

}

void widgtimer::getTime(QTime currentTime)
{
    hh = currentTime.hour();
    mm = currentTime.minute();
    ss = currentTime.second();
}

void widgtimer::timeDecs()
{

    if(ss == 0)
    {
        if(mm == 0)
        {
            if(hh == 0)
            {
                emit signalTimeOut();
                onCounterStop();
                return;
            }
            else
            {
                mm = 59;
                hh--;
            }
        }
        else
        {
            ss = 59;
            mm--;
        }
    }
    else
    {
        ss--;
    }
}

void widgtimer::onCounterStart()
{
    mtimer->start(1000);
}

void widgtimer::onCounterStop()
{
    mtimer->stop();
    ss = mm = hh = 0;
    mtime = QTime::fromString("00:00:00","hh:mm:ss");
    emit signalTimeChange(mtime);
}

void widgtimer::onCountDownSec()
{
   timeDecs();
   mtime = QTime::fromString(QString::number(hh)+":"+QString::number(mm)+":"+QString::number(ss),"h:m:s");
   emit signalTimeChange(mtime);
}
