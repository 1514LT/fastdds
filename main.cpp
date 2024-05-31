#include "SQLite.hpp"
#include "DDSBase.h"
#include "DDSBasePublisher.h"
#include "DDSBaseSubscriber.h"

int main(int argc, char const *argv[])
{
  SQLite sql;
  std::string path = JRLC::getUserPath();
  std::string strJson = JRLC::read_file_contents("../profile/sqliteInit.json");
  Json::Value sqliteInit = JRLC::StringToJson(strJson);
  sql.Init(sqliteInit);

  return 0;
}
