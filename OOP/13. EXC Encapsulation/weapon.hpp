#ifndef __WEAPON
#define __WEAPON

#include <string>

class Weapon{
  private:
    std::string name;
    double atkPower;
  
  public:
    Weapon(const char*, double);
    void display();
    // getter, read only
    std::string getName();
    double getPower();
};

#endif