#ifndef __PLAYER
#define __PLAYER

#include <string>
#include "weapon.hpp"

class Player{
  private:
    std::string name;
    int level;
    int exp;
    int maxExp;
    double health;
    double maxHealth; 
    Weapon* weapon;

  public:
    Player(std::string, int level = 1, int exp = 0, int maxExp = 100, double health = 100, double maxHealth = 100);
    std::string getName();
    int getLevel();
    int getExp();
    int getMaxExp();
    double getHealth();
    double getMaxHealth();
    Weapon* getWeapon();

    void equipWeapon(Weapon* &);
    void fighting();
    void sleep();
    std::string stringify();

};

#endif