#include <iostream>

// external definition
#include "player.h"

using namespace std;

int main() {
  Player* player1 = new Player("Bogeng");
  player1->display();
  return 0;
}