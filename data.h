#ifndef DATA_H
#define DATA_H

#include <QString>
#include <set>
using namespace std; 

class Data {

 public:
  Data();
  ~Data();


  
  

  map<int, string> armorNames;
  map<int, string> unitNames; 

 private:
  
  /* Members */
  vector<pair <int, string> > armors;
  vector<pair <int, string> > units;
  

  /* Functions */
  vector< pair<int, string> > readFile(QString fileName);
  pair<int, string> tokenize(QString s);
  

}; 

#endif
