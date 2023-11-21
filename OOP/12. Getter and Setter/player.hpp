#ifndef __PLAYER
#define __PLAYER

#include <string>

class Player{
  private:
    std::string name;
    double attackPower;
    int level;
    int exp;


  public:
    Player(const char*);

    void display();

    // getter, making attributes to read only data (store the attributes to private)
    // access it using methods from public
    std::string getName();

    // setter, to write data to object's member attributes
    void setExp(int);
};

#endif