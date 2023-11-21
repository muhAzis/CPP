#ifndef __PLAYER
#define __PLAYER

#include <string>
#include "weapon.hpp"

class Player{
  private:
    std::string name;
    Weapon* weapon;
  
  public:
    Player(const char*);
    void display();
    // setter
    void equipWeapon(Weapon*);
};

#endif