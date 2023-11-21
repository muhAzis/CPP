#include <iostream>
#include "weapon.hpp"

Weapon::Weapon(const char* name, double atkPower) {
  this->name = name;
  this->atkPower = atkPower;
}

void Weapon::display() {
  std::cout << "Weapon: " << std::endl;
  std::cout << "- Name\t: " << this->name << std::endl;
  std::cout << "- Power\t: " << this->atkPower << std::endl;
}

std::string Weapon::getName() {
  return this->name;
}

double Weapon::getPower() {
  return this->atkPower;
}