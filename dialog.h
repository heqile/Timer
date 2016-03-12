#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "widgcounter.h"
#include "widgtimer.h"
#include <QMessageBox>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
    widgcounter *mCounter;
    widgtimer *mTimer;

private slots:
    void onCountDownSec(QTime);
    void onTimerDownSec(QTime);
    void onTimerStart();
    void onTimerTimeOut();
};

#endif // DIALOG_H
