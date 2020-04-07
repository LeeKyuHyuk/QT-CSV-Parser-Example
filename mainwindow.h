#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include "filereadthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    enum Columns
    {
        ANTINUCLEUS, EVENTFILE, EVENTNUMBER, EVENTTIME, HISTFILE, MULTIPLICITY ,
        NABOVELB, NBELOWLB, NLB, PRIMARYTRACKS, PRODTIME, PT, RUNNUMBER ,
        VERTEXX, VERTEXY, VERTEXZ
    };
    FileReadThread *fileReadThread;
    void tableSetting();

private slots:
    void on_actionOpen_triggered();
    void addData(QString antiNucleus, QString eventFile, QString eventNumber, QString eventTime, QString histFile, QString multiplicity ,
                 QString NaboveLb, QString NbelowLb, QString NLb, QString primaryTracks, QString prodTime, QString Pt, QString runNumber ,
                 QString vertexX, QString vertexY, QString vertexZ);
    void errorMessageBox(QString msg);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
