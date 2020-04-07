#include "filereadthread.h"

FileReadThread::FileReadThread()
{
}

void FileReadThread::setFileName(QString filename)
{
    this->filename = filename;
}

void FileReadThread::run()
{
    QFile File(filename);
    if(!File.open(QFile::ReadOnly|QFile::Text))
    {
        if(!File.exists())
        {
            emit ErrorMessageBox("파일이 존재하지 않습니다.");
            return;
        }
        else
        {
            emit ErrorMessageBox("파일을 열 수 없거나, 파일이 손상되었습니다.");
            return;
        }
    }
    QTextStream OpenFile(&File);
    if(OpenFile.readLine() != "antiNucleus, eventFile, eventNumber, eventTime, histFile, multiplicity, NaboveLb, NbelowLb, NLb, primaryTracks, prodTime, Pt, runNumber, vertexX, vertexY, vertexZ")
    {
        emit ErrorMessageBox("잘못된 파일 형식입니다.");
        return;
    }
    while(!OpenFile.atEnd())  // 파일 끝까지 읽어서
    {
        QString line=OpenFile.readLine(); // 한라인씩 읽어서 변수에 적용
        QStringList data = line.split(',');
        emit AddData(data[0], data[1], data[2], data[3], data[4], data[5], data[6], data[7], data[8], data[9], data[10], data[11], data[12], data[13], data[14], data[15]);
    }
    File.close();
    qDebug() << "Done!";
}
