#ifndef DATA_H
#define DATA_H

#include <QString>
#include <set>
using namespace std; 

class Data {

 public:
  Data();
  ~Data();



  vector<pair <int, string> > armors;
  vector<pair <int, string> > units;  

 private:
  
  /* Members */

  

  /* Functions */
  vector< pair<int, string> > readFile(QString fileName);
  pair<int, string> tokenize(QString s);
  

}; 

#endif
