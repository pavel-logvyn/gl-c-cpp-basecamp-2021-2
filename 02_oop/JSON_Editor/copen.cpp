#include "copen.h"
#include <QTextStream>
#include <QFileDialog>
#include <QMessageBox>
#include <QObject>
#include "./ui_mainwindow.h"
#include "csave.h"
#include "savechanges.h"

cOpen::cOpen(bool &edited_, Ui::MainWindow *ui_, MainWindow *th):edited(&edited_), ui(ui_), form(th){}

void cOpen::exec() const
{
    int temp=0;
    if(*edited)
    {
        temp = saveChanges();
        if(temp == QMessageBox::Save){
            Invoker invoker;
            invoker.exec(new cSave(ui, form));
        }
    }
    if(!(temp == QMessageBox::Cancel)){
        QString fileName = QFileDialog::getOpenFileName(form, QString::fromUtf8("Save the File"), "",
                                                        QString::fromUtf8("Text file (*.txt);;JSON file (*.json)"));
        if (fileName.isEmpty())
                return;
        else {
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly)) {
                QMessageBox::information(form, QObject::tr("Unable to open a file"),
                    file.errorString());
                return;
            }

            QTextStream in(&file);
            ui->textEdit->clear();
            ui->textEdit->setEnabled(true);
            QString temp;
            in >> temp;
            ui->textEdit->setPlainText(temp);
    }
    }
}