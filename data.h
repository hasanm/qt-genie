#ifndef DATA_H
#define DATA_H

#include <QString>
#include <set>


#include "genie/dat/DatFile.h"

using namespace std;


class Data {

 public:
  Data();
  ~Data();

  map<int, string> armorNames;
  map<int, string> unitNames;

  map<std::uint32_t, genie::Unit> unitMap;
  map<std::string, std::uint32_t> nameMap;
  map<std::uint32_t, int> whiteListMap;  

 private:
  
  /* Members */
  vector<pair <int, string> > armors;
  vector<pair <int, string> > units;
  vector<pair <int, string> > whiteLists;  
  

  /* Functions */
  vector< pair<int, string> > readFile(QString fileName);
  pair<int, string> tokenize(QString s);
  

}; 

#endif
