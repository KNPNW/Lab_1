#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "array.h"
#include "popyriclass.h"
#include "muscompclass.h"
#include <QHeaderView>
#include <QStringLiteral>
#include <QIntValidator>
#include <QAbstractItemModel>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>

SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::addData(const Array& result){
    resultSort.copyArray(result);
    ui->textBrowser->clear();

    for (int i = 0; i < resultSort.getSize(); i++) {
        MusCompClass *music = resultSort.getObject(i);
        if(music->get_class() == "MusCompClass"){
            QString item = (QString("Element# ")
                            +QString(std::to_string(i).c_str())
                            +QString(" - MusicComposition\n")
                            +QString(music->getAuthor().c_str())
                            +QString(" - ")
                            +QString(music->getName().c_str())
                            +QString("\n")
                            +QString(std::to_string(music->getMood().first).c_str())
                            +QString("\n")
                            +QString(std::to_string(music->getMood().second).c_str())
                            +QString("\n"));
            ui->textBrowser->append(item);
        }else{
            PopyriClass* poppyri = (PopyriClass*) music;
            QString item = (QString("Element# ")
                            +QString(std::to_string(i).c_str())
                            +QString(" - Poppyri\n")
                            +QString(poppyri->getAuthor().c_str())
                            +QString(" - ")
                            +QString(poppyri->getName().c_str())
                            +QString("\n")
                            +QString(std::to_string(poppyri->getMood().first).c_str())
                            +QString("\n")
                            +QString(std::to_string(poppyri->getMood().second).c_str())
                            +QString("\n")
                            +QString(std::to_string(poppyri->getPopyriMood().startMood).c_str())
                            +QString("   ")
                            +QString(std::to_string(poppyri->getPopyriMood().finishMood).c_str())
                            +QString("\n"));
            ui->textBrowser->append(item);
        }
    }
}
