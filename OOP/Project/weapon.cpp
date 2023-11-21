#include <string>
#include "weapon.hpp"

Weapon::Weapon(std::string &name, double power) {
  this->name = name;
  this->power = power;
}

std::string Weapon::getName() {
  return this->name;
}

double Weapon::getPower() {
  return this->power;
}