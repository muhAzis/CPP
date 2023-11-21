#include <iostream>
#include <string>

// external definition
#include "player.h"

using namespace std;

Player::Player(const char* name) {
  this->name = name;
}

void Player::display() {
  cout << "Nama Player: " << this->name << endl;
}