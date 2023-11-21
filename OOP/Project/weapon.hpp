#ifndef __WEAPON
#define __WEAPON

#include <string>

class Weapon{
  private:
    std::string name;
    double power;
  
  public:
    Weapon(std::string &, double);
    std::string getName();
    double getPower();
};

#endif