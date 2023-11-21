#include <iostream>
#include <string>
#include "player.hpp"

Player::Player(const char* name) {
  this->name = name;
  this->level = 1;
  this->exp = 0;
  this->attackPower = 100;
}

void Player::display() {
  std::cout << "Name\t: " << this->name << std::endl;
  std::cout << "Level\t: " << this->level << "\nExp\t: " << this->exp << std::endl;
  std::cout << "Attack\t: " << this->attackPower << std::endl;
}

// getter, making attributes to read only data (store the attributes to private)
// access it using methods from public
std::string Player::getName() {
  return this->name;
}

// setter, to write data to object's member attributes
void Player::setExp(int exp) {
  int maxExp = 100;
  this->exp += exp;
  std::cout << "Exp +" << exp << " : " << this->exp << std::endl;

  if(this->exp >= maxExp) {
    this->level += this->exp/maxExp;
    this->attackPower += 100*(this->exp/maxExp);
    this->exp = this->exp%maxExp;
    std::cout << "LEVEL UP!!" << std::endl;
  }
}