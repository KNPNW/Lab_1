#include "resultwindow.h"
#include "ui_resultwindow.h"
#include "array.h"
#include "popyriclass.h"
#include <iostream>

ResultWindow::ResultWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ResultWindow)
{
    ui->setupUi(this);
}


ResultWindow::~ResultWindow()
{
    delete ui;
}

void ResultWindow::addData(Array &result){
    printAllArray(result);
    ui->textBrowser2->clear();
    for (int i = 0; i < result.getSize(); i++) {
        MusCompClass *music = result.getObject(i);
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
            ui->textBrowser2->append(item);
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
            ui->textBrowser2->append(item);
        }
    }
}

//void ResultWindow::on_pushRButton_clicked(){
//    ui->textBrowser->clear();

//    for (int i = 0; i < resMusArr.getSize(); i++) {
//        MusCompClass *music = resMusArr.getObject(i);
//        if(music->get_class() == "MusCompClass"){
//            QString item = (QString("Element# ")
//                            +QString(std::to_string(i).c_str())
//                            +QString(" - MusicComposition\n")
//                            +QString(music->getAuthor().c_str())
//                            +QString(" - ")
//                            +QString(music->getName().c_str())
//                            +QString("\n")
//                            +QString(std::to_string(music->getMood().first).c_str())
//                            +QString("\n")
//                            +QString(std::to_string(music->getMood().second).c_str())
//                            +QString("\n"));
//            ui->textBrowser->append(item);
//        }else{
//            PopyriClass* poppyri = (PopyriClass*) music;
//            QString item = (QString("Element# ")
//                            +QString(std::to_string(i).c_str())
//                            +QString(" - Poppyri\n")
//                            +QString(poppyri->getAuthor().c_str())
//                            +QString(" - ")
//                            +QString(poppyri->getName().c_str())
//                            +QString("\n")
//                            +QString(std::to_string(poppyri->getMood().first).c_str())
//                            +QString("\n")
//                            +QString(std::to_string(poppyri->getMood().second).c_str())
//                            +QString("\n")
//                            +QString(std::to_string(poppyri->getPopyriMood().startMood).c_str())
//                            +QString("   ")
//                            +QString(std::to_string(poppyri->getPopyriMood().finishMood).c_str())
//                            +QString("\n"));
//            ui->textBrowser->append(item);
//        }
//    }
//}
