#ifndef __SQLITE_HPP
#define __SQLITE_HPP
#include "sqlite3/sqlite3.h"
#include "dataProcess.hpp"
class SQLite
{
private:
  std::map<std::string,sqlite3*> m_DBMap;
public:
  SQLite();
  ~SQLite();

public:
  sqlite3* getDB(std::string nameDB);
  void setDB(std::string nameDB);
  bool sqliteExec(std::string nameDB,std::string cmd);
  bool Init(Json::Value root);
};



#endif