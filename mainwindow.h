#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "array.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_Open_file_triggered();

    void on_Save_how_triggered();

    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_action_triggered();

    void on_action_2_triggered();

    void on_sortButton_clicked();

protected slots:

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Array musArray, resultSort;
};
#endif // MAINWINDOW_H
