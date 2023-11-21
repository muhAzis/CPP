#include <iostream>
#include "player.hpp"

using namespace std;

int main() {
  Player* player1 = new Player("Jotaro");
  player1->display();
  cout << player1->getName() << endl << endl;; // the name become a read-only data
  // player1->name = "Kurosaki"; // can't be done because it is stored in private

  player1->setExp(25);
  player1->setExp(68);
  player1->setExp(43);
  player1->setExp(75);

  cout << endl;
  player1->display();

  return 0;
}