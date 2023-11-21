#include <iostream>
#include <fstream>
#include "database.hpp"
#include "player.hpp"
#include "weapon.hpp"

DataBase::DataBase(const char* dbName) {
  this->dbName = dbName;
}

void DataBase::createDb() {
  this->out.open(this->dbName, std::ios::trunc);
  this->out.close();
}

bool DataBase::isExist() {
  bool state;
  this->in.open(this->dbName, std::ios::in);
  if(this->in.fail()) {
    return 0;
  }
  this->in.close();

  return 1;
}

bool DataBase::isEmpty() {
  bool state;
  this->in.open(this->dbName, std::ios::in);
  state = this->in.peek() == std::ifstream::traits_type::eof();
  this->in.close();
  return state;
}

void DataBase::savePlayer(Player* &player) {
  this->out.open(this->dbName, std::ios::trunc);
  this->out << player->stringify();
  this->out.close();
}

Player* DataBase::getPlayerData(DataBase* &db) {
  std::string name, level, exp, maxExp, health, maxHealth, wpnName, wpnPower;
  int iLevel, iExp;
  double dHealth, dMaxHealth, dPower;

  this->in.open(this->dbName, std::ios::in);
  while(!this->in.eof()) {
    getline(this->in, name, ',');
    getline(this->in, level, ',');
    getline(this->in, exp, ',');
    getline(this->in, maxExp, ',');
    getline(this->in, health, ',');
    getline(this->in, maxHealth, ',');
    getline(this->in, wpnName, ',');
    getline(this->in, wpnPower);
  }
  this->in.close();

  Player* player = new Player(name, std::stoi(level), std::stoi(exp), std::stoi(maxExp), std::stod(health), std::stod(maxHealth));
  Weapon* weapon = new Weapon(wpnName, std::stod(wpnPower));
  player->equipWeapon(weapon);

  return player;
}