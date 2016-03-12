#ifndef WIDGTIMER_H
#define WIDGTIMER_H

#include <QObject>
#include "timer.h"
#include <QTime>

class widgtimer : public QObject
{
    Q_OBJECT
public:
    explicit widgtimer(QObject *parent = 0);
    void getTime(QTime);
private:
    timer *mtimer;
    QTime mtime;
    int hh;
    int mm;
    int ss;
    void timeDecs();
signals:
    void signalTimeChange(QTime );
    void signalTimeOut();
public slots:
    void onCounterStart();
    void onCounterStop();
    void onCountDownSec();
};

#endif // WIDGTIMER_H
