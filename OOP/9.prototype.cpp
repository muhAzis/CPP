#include <iostream>
#include <string>

using namespace std;

class Player{
  public:
    string name;

    // just like normal methods/functions, we can make the object's member method a prototype too
    // even the constructor
    Player(const char*);
    void display();
};

// declare the method/function outside the object
Player::Player(const char* name) {
  this->name = name;
}

int main() {
  Player* player1 = new Player("Bogeng");
  player1->display();
  return 0;
}

// or you can also put it after main method
void Player::display() {
  cout << "Nama Player: " << this->name << endl;
}