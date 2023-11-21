#ifndef __DATABASE
#define __DATABASE

#include <string>
#include <fstream>
#include "player.hpp"

class DataBase{
  private:
    std::ifstream in;
    std::ofstream out;
    std::string dbName;
  
  public:
    DataBase(const char*);
    void createDb();
    bool isExist();
    bool isEmpty();
    void savePlayer(Player* &);
    Player* getPlayerData(DataBase* &);
};

#endif