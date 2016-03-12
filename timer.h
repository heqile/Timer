#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTimer>

class timer : public QTimer
{
    Q_OBJECT
public:
    explicit timer(QObject *parent = 0);
private:

signals:

public slots:

};

#endif // TIMER_H
