#include "SQLite.hpp"

SQLite::SQLite(/* args */)
{
}

SQLite::~SQLite()
{
}

bool SQLite::Init(Json::Value root)
{
  std::string nameDB = root["nameDB"].asString();
  std::string tableName = root["tableName"].asString();
  std::vector<std::string> reule_vt;
  Json::Value ruleArray = root["rule"];
  std::string cmd_create = "CREATE TABLE IF NOT EXISTS " + tableName + "(";

  for(int i = 0; i < ruleArray.size(); i++) 
  {
    Json::Value ruleObject = ruleArray[i];
    Json::Value::Members members = ruleObject.getMemberNames();
    for (Json::Value::Members::iterator it = members.begin(); it != members.end(); ++it) 
    {
      const std::string &key = *it;
      const Json::Value &value = ruleObject[key];
      std::cout << "Key: " << key << ", Value: " << value.asString() << std::endl;
      cmd_create += key + " " + value.asString();
      if (i != ruleArray.size() - 1 || it != --members.end())
      {
        cmd_create += ",";
      }
    }
  }
  cmd_create += ");";
  std::cout << cmd_create << std::endl;
  setDB(nameDB);
  bool flag = sqliteExec(nameDB,cmd_create);
  return flag;
}

sqlite3* SQLite::getDB(std::string nameDB)
{
  bool falg = false;
  for(auto db:m_DBMap)
  {
    if(db.first == nameDB)
    {
      falg = true;
    }
  }
  if(falg)
    return m_DBMap[nameDB];
  return nullptr;
}
void SQLite::setDB(std::string nameDB)
{
  sqlite3* DB;
  int exit = 0;
  exit = sqlite3_open(nameDB.c_str(), &DB);
  if (exit) 
  {
    std::cerr << "Cannot open database: " << sqlite3_errmsg(DB);
  }
  else
  {
    std::cout << "Opened database successfully" << std::endl;
    m_DBMap[nameDB] = DB;
  }
}
bool SQLite::sqliteExec(std::string nameDB,std::string cmd)
{
  int exit = 0;
  char* messageError;
  sqlite3* DB = getDB(nameDB);
  exit = sqlite3_exec(DB, cmd.c_str(), NULL, 0, &messageError);
  if (exit != SQLITE_OK)
  {
    std::cerr << "Error Create Table" << std::endl;
    sqlite3_free(messageError);
    return false;
  }
  else
  {
    std::cout << "Table created Successfully" << std::endl; 
  }
  return true;  
}