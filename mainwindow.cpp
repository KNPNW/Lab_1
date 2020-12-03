#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "array.h"
#include "muscompclass.h"
#include "secondwindow.h"
#include "popyriclass.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <QHeaderView>
#include <QStringLiteral>
#include <QIntValidator>
#include <QAbstractItemModel>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->numberElForDel->setValidator(new QIntValidator);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Open_file_triggered()
{
    QString qs = QFileDialog::getOpenFileName(this, "Open MusComopirions", ".", "TEXT files (*.txt)");
    std::string filename = qs.toUtf8().constData();
    try {
        if (musArray.getSize() > 0)
            musArray.delAll();
        musArray.fromFile(filename);
        on_pushButton_clicked();
    } catch (exception) {
        QMessageBox::critical(this, "Ошибка", "Ошибка при чтении данных");
    }
}

void MainWindow::on_Save_how_triggered()
{
    QString qs = QFileDialog::getSaveFileName(this, "Save the file");
    std::string filename = qs.toUtf8().constData();
    musArray.toFile(filename);
}

void MainWindow::on_pushButton_clicked(){
    ui->textBrowser->clear();

    for (int i = 0; i < musArray.getSize(); i++) {
        MusCompClass *music = musArray.getObject(i);
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

void MainWindow::on_addButton_clicked()
{
    string nameM, nameA;
    double firstM, secondM, startM, finishM;
    startM = ui->sbStartMood->value();
    finishM = ui->sbFinishMood->value();
    firstM = ui->sbFirstMood->value();
    secondM = ui->sbSecondMood->value();
    nameA = ui->nameAuthor->text().toStdString();
    nameM = ui->nameComp->text().toStdString();
    if(startM == 0.0 || finishM == 0.0){
        if(nameA == "" || nameM == ""){
            QMessageBox::critical(0, "Внимание","Не введено имя автора или название композиции!");
        }else{
            if (firstM == 0.0 || secondM == 0.0){
                QMessageBox::critical(0, "Внимание","Не введены настроения!");
            }else{
                MusCompClass* obj = new MusCompClass(nameM, nameA, {firstM, secondM});
                ui->nameAuthor->clear();
                ui->nameComp->clear();
                ui->sbFirstMood->setValue(0.0);
                ui->sbSecondMood->setValue(0.0);
                musArray.pushBack(obj);
                on_pushButton_clicked();
            }
        }

    }else{
        if(nameA == "" || nameM == ""){
            QMessageBox::critical(0, "Внимание","Не введено имя автора или название композиции!");
        }else{
            if (firstM == 0.0 || secondM == 0.0){
                QMessageBox::critical(0, "Внимание","Не введены настроения!");
            }else{
                PopyriClass*obj = new PopyriClass(nameM, nameA, {firstM, secondM}, {startM, finishM});
                ui->nameAuthor->clear();
                ui->nameComp->clear();
                ui->sbFirstMood->setValue(0.0);
                ui->sbSecondMood->setValue(0.0);
                ui->sbFirstMood->setValue(0.0);
                ui->sbFinishMood->setValue(0.0);
                musArray.pushBack(obj);
                on_pushButton_clicked();
            }
        }

    }
}

void MainWindow::on_deleteButton_clicked()
{
    int numDel = ui->numberElForDel->text().toInt();
    if (numDel >= musArray.getSize()){
         QMessageBox::critical(0, "Внимание","Указан номер не существующего обьекта!");
    }
    else{
        musArray.del(numDel);
        ui->numberElForDel->clear();
        on_pushButton_clicked();
    }
}

void MainWindow::on_action_triggered()
{
    musArray.delAll();
    on_pushButton_clicked();
}

void MainWindow::on_action_2_triggered()
{
    ui->nameAuthor->clear();
    ui->nameComp->clear();
    ui->numberElForDel->clear();
    ui->sbFirstMood->setValue(0.0);
    ui->sbSecondMood->setValue(0.0);
    ui->sbFirstMood->setValue(0.0);
    ui->sbFinishMood->setValue(0.0);
}

void MainWindow::on_sortButton_clicked()
{
    double minFMood, maxFMood, minSMood, maxSMood;
    minFMood = ui->minFMood->value();
    maxFMood = ui->maxFMood->value();
    minSMood = ui->minSMood->value();
    maxSMood = ui->maxSMood->value();
    resultSort = musArray.sortLimit(minFMood, maxFMood, minSMood, maxSMood);

    ui->textBrowser_2->clear();
    QString item = (QString("Это к сожалению не работает(")
                    +QString("\n")
                    +QString("Но грустить не надо)"));
    ui->textBrowser_2->append(item);

//    SecondWindow dialog;
//    dialog.show();
//    dialog.addData(resultSort);

//    ui->textBrowser_2->clear();
//    int size = resultSort.getSize();
//    for (int i = 0; i < size; i++) {
//        MusCompClass *music = resultSort.getObject(i);
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
//            ui->textBrowser_2->append(item);
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
//            ui->textBrowser_2->append(item);
//        }
//    }
}
