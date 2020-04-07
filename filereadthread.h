#ifndef FILEREADTHREAD_H
#define FILEREADTHREAD_H

#include <QObject>
#include <QThread>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class FileReadThread : public QThread
{
    Q_OBJECT

public:
    FileReadThread();
    void setFileName(QString filename);

private:
    QString filename;

protected:
    void run() override;

signals:
    void AddData(QString antiNucleus, QString eventFile, QString eventNumber, QString eventTime, QString histFile, QString multiplicity ,
                 QString NaboveLb, QString NbelowLb, QString NLb, QString primaryTracks, QString prodTime, QString Pt, QString runNumber ,
                 QString vertexX, QString vertexY, QString vertexZ);
    void ErrorMessageBox(QString msg);
};

#endif // FILEREADTHREAD_H
