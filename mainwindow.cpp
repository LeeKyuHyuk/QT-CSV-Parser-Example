#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fileReadThread = new FileReadThread();
    connect(fileReadThread, SIGNAL(AddData(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString)),
            this, SLOT(addData(QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString)));
    connect(fileReadThread, SIGNAL(ErrorMessageBox(QString)), this, SLOT(errorMessageBox(QString)));
    tableSetting();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tableSetting()
{
    QStringList tableHeader;
    tableHeader << "antiNucleus" << "eventFile" << "eventNumber" << "eventTime" << "histFile" << "multiplicity"
                << "NaboveLb" << "NbelowLb" << "NLb" << "primaryTracks" << "prodTime" << "Pt" << "runNumber"
                << "vertexX" << "vertexY" << "vertexZ";
    ui->tableWidget->setColumnCount(16);
    ui->tableWidget->setHorizontalHeaderLabels(tableHeader);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

/*
 * MainWindow Slots
 */
void MainWindow::on_actionOpen_triggered()
{
    const QString strFilter = "csv file (*.csv) ;; All files (*.*)";
    QString strFileName = QFileDialog::getOpenFileName(this, "Open a file", QDir::homePath() , strFilter);
    fileReadThread->setFileName(strFileName);
    fileReadThread->start();
}

void MainWindow::addData(QString antiNucleus, QString eventFile, QString eventNumber, QString eventTime, QString histFile, QString multiplicity ,
                         QString NaboveLb, QString NbelowLb, QString NLb, QString primaryTracks, QString prodTime, QString Pt, QString runNumber ,
                         QString vertexX, QString vertexY, QString vertexZ)
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    int index = ui->tableWidget->rowCount() - 1;
    ui->tableWidget->setItem(index, ANTINUCLEUS, new QTableWidgetItem(antiNucleus));
    ui->tableWidget->setItem(index, EVENTFILE, new QTableWidgetItem(eventFile));
    ui->tableWidget->setItem(index, EVENTNUMBER, new QTableWidgetItem(eventNumber));
    ui->tableWidget->setItem(index, EVENTTIME, new QTableWidgetItem(eventTime));
    ui->tableWidget->setItem(index, HISTFILE, new QTableWidgetItem(histFile));
    ui->tableWidget->setItem(index, MULTIPLICITY, new QTableWidgetItem(multiplicity));
    ui->tableWidget->setItem(index, NABOVELB, new QTableWidgetItem(NaboveLb));
    ui->tableWidget->setItem(index, NBELOWLB, new QTableWidgetItem(NbelowLb));
    ui->tableWidget->setItem(index, NLB, new QTableWidgetItem(NLb));
    ui->tableWidget->setItem(index, PRIMARYTRACKS, new QTableWidgetItem(primaryTracks));
    ui->tableWidget->setItem(index, PRODTIME, new QTableWidgetItem(prodTime));
    ui->tableWidget->setItem(index, PT, new QTableWidgetItem(Pt));
    ui->tableWidget->setItem(index, RUNNUMBER, new QTableWidgetItem(runNumber));
    ui->tableWidget->setItem(index, VERTEXX, new QTableWidgetItem(vertexX));
    ui->tableWidget->setItem(index, VERTEXY, new QTableWidgetItem(vertexY));
    ui->tableWidget->setItem(index, VERTEXZ, new QTableWidgetItem(vertexZ));
}

void MainWindow::errorMessageBox(QString msg)
{
    QMessageBox::critical(this, "Error", msg);
}
