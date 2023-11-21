#include <iostream>
#include "player.hpp"
#include "weapon.hpp"

Player::Player(const char* name) {
  this->name = name;
}

void Player::display() {
  std::cout << "Player name: " << this->name << std::endl;
  std::cout << "Weapon used:" << std::endl;
  std::cout << "-name\t: " << this->weapon->getName() << std::endl;
  std::cout << "-power\t: " << this->weapon->getPower() << std::endl;
}

void Player::equipWeapon(Weapon* weapon) {
  this->weapon = weapon;
}