#include <iostream>
#include <string>
#include <cstdlib>
#include "player.hpp"
#include "weapon.hpp"

Player::Player(std::string name, int level, int exp, int maxExp, double health, double maxHealth) {
  this->name = name;
  this->level = level;
  this->exp = exp;
  this->maxExp = maxExp;
  this->health = health;
  this->maxHealth = maxHealth;
}

std::string Player::getName() {
  return this->name;
}

int Player::getLevel() {
  return this->level;
}

int Player::getExp() {
  return this->exp;
}

int Player::getMaxExp() {
  return this->maxExp;
}

double Player::getHealth() {
  return this->health;
}

double Player::getMaxHealth() {
  return this->maxHealth;
}

Weapon* Player::getWeapon() {
  return this->weapon;
}

std::string Player::stringify() {
  return (
    this->name + "," +
    std::to_string(this->level) + "," +
    std::to_string(this->exp) + "," +
    std::to_string(this->maxExp) + "," +
    std::to_string(this->health*100/100) + "," +
    std::to_string(this->maxHealth*100/100) + "," +
    this->weapon->getName() + "," +
    std::to_string(this->weapon->getPower()) + ","
  );
}

void Player::equipWeapon(Weapon* &weapon) {
  this->weapon = weapon;
}

void Player::fighting() {
  int randomExp = std::rand() % this->maxExp;
  double randomDmg = std::rand() % int(this->maxHealth);
  this->exp += randomExp;
  this->health -= randomDmg;
  if(this->exp >= this->maxExp && this->health > 0) {
    system("clear");
    std::cout << "You win! Congratulations!\n" << std::endl;
    std::cin.get();
    std::cout << "LEVEL UP!!" << std::endl;
    std::cout << "Exp +" << randomExp << std::endl;
    std::cout << "HP -"<< randomDmg << std::endl;
    this->level++;
    this->exp = this->exp % this->maxExp;
    this->maxExp += this->maxExp/2;
    this->maxHealth = 100 * this->level;
    this->health = this->maxHealth;
  } else if(this->health <= 0) {
    system("clear");
    std::cout << "You Lose!" << std::endl;
    std::cin.get();
  } else {
    system("clear");
    std::cout << "You win! Congratulations!\n" << std::endl;
    std::cin.get();
    std::cout << "Exp +" << randomExp << std::endl;
    std::cout << "HP -"<< randomDmg << std::endl;
  }
  
}

void Player::sleep() {
  this->health = this->maxHealth;
}