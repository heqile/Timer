#ifndef WIDGCOUNTER_H
#define WIDGCOUNTER_H

#include <QObject>
#include "timer.h"
#include <QThread>
#include <QTime>

class widgcounter : public QObject
{
    Q_OBJECT
public:
    explicit widgcounter(QObject *parent = 0);
private:
//    QThread *mthread;
    timer *mtimer;
    QTime mtime;
    int hh;
    int mm;
    int ss;
    void timeAccumu();
signals:
    void signalPlusSec(QTime );
public slots:
    void onCounterStart();
    void onCounterStop();
    void onCountDownSec();
    void onCountPause();
};

#endif // WIDGCOUNTER_H
