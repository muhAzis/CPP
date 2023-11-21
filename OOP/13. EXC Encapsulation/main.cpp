#include <iostream>
#include <string>
#include "player.hpp"
#include "weapon.hpp"

using namespace std;

int main() {
  Player* player1 = new Player("Gunga");
  Weapon* wpn1 = new Weapon("Rifle", 50);

  // setter implementation to equip weapon
  player1->equipWeapon(wpn1);
  player1->display();

  return 0;
}