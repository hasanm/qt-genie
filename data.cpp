#include <QtWidgets>
#include <QString>
#include <QFile>


#include "data.h"

Data::Data()
{
  QString classFileName(":/resources/class.txt");
  QString unitFileName (":/resources/units.txt");

  readFile(classFileName);
  readFile(unitFileName);
}

Data::~Data() {
}


void Data::readFile(QString fileName)
{
  QFile file (fileName);
  QString content;

  if (!file.open(QIODevice::ReadOnly)) {
    qDebug() << fileName << " not found"; 
  } else {
    qDebug() << fileName << " opened";
    content = file.readAll();
  }

  file.close();
}
