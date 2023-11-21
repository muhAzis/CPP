// declare the Class object template
#ifndef __PLAYER
#define __PLAYER
#include <string>

using namespace std;

class Player{
  public:
    string name;

    Player(const char*);
    void display();
};

#endif