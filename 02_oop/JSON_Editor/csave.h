#ifndef CSAVE_H
#define CSAVE_H

#include "mainwindow.h"
#include "command.h"
class cSave : public Command
{
private:
    Ui::MainWindow *ui;
    MainWindow *form;
public:
    cSave(Ui::MainWindow *ui_, MainWindow *th);
    ~cSave();
    void exec()const override;
};

#endif // CSAVE_H