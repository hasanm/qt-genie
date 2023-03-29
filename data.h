#ifndef DATA_H
#define DATA_H

#include <QString>

class Data {

 public:
  Data();
  ~Data();

 private:
  void readFile(QString fileName);
}; 

#endif
