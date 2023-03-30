#include <QtWidgets>
#include <QString>
#include <QFile>
#include <set>
#include <string>
#include <boost/algorithm/string.hpp>


#include "data.h"

using namespace std;
using namespace boost::algorithm;


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

  if (!file.open(QIODevice::ReadOnly)) {
    qDebug() << fileName << " not found"; 
  } else {
    qDebug() << fileName << " opened";

    while (!file.atEnd()){
      QByteArray line = file.readLine();
      tokenize(line);
    }
  }

  file.close();
}

pair<int, string> Data::tokenize(QString in)
{
  string s = in.toStdString();
  int start = 0;
  int end = s.find(":");

  string first = s.substr(start, end - start);
  trim(first);
  first = erase_all_copy(first, "\"");

  qDebug() << in << " : " << end;
  qDebug() << first.c_str();

  start = end + 1;
  string second = s.substr(start);
  trim(second);
  second = erase_all_copy(second, "\"");

  qDebug() << second.c_str();

  pair <int, string> result = make_pair(stoi(first), second);

  return result; 
}

