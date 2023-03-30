#include <iostream>
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


  armors = readFile(classFileName);
  units = readFile(unitFileName);

  for (auto token : armors){
    armorNames[token.first] = token.second; 
  }

  for (auto token : units) {
    unitNames[token.first] = token.second;
  }


}

Data::~Data() {
}


vector<pair<int, string>> Data::readFile(QString fileName)
{
  QFile file (fileName);
  vector <pair <int, string>> result; 

  if (!file.open(QIODevice::ReadOnly)) {
    qDebug() << fileName << " not found"; 
  } else {
    qDebug() << fileName << " opened";

    while (!file.atEnd()){
      QByteArray line = file.readLine();
      pair<int, string> token = tokenize(line);
      result.push_back(token);
    }
  }

  file.close();
  return result; 
}

pair<int, string> Data::tokenize(QString in)
{
  string s = in.toStdString();
  int start = 0;
  int end = s.find(":");

  string first = s.substr(start, end - start);
  trim(first);
  first = erase_all_copy(first, "\"");

  start = end + 1;
  string second = s.substr(start);
  trim(second);
  second = erase_all_copy(second, "\"");

  pair <int, string> result = make_pair(stoi(first), second);

  return result; 
}

