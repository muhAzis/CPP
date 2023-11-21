#include <iostream>
#include <string>

using namespace std;

class Player{
  public:
    string nama;

    // constructor, run when an object created
    Player(const char* nama) {
      cout << "Player " << nama << " dibuat!" << endl;
      Player::nama = nama;
    }

    // destructor, run when an object deleted
    ~Player() {
      cout << "Player " << Player::nama << " deleted!" << endl;
    }

};

void createPlayerStack() {
  Player player3 = Player("Cupung");
}

void createPlayerHeap() {
  Player* player4 = new Player("Kuproy");
  delete player4;
}

void createPlayerStackPointer(Player* &player) {
  Player player5 = Player("Kuncup");
  player = &player5;
  // will cause segmentation error, because after player5 is passed to player and the function ends,
  // player5 already been deleted from Stack Memory
}

void createPlayerHeapPointer(Player* &player) {
  Player* player6 = new Player("Bogeng");
  player = player6;
  delete player6;
  // it will not causing an error, it's just like you're copying the object
  // when player6 deleted, player already have the data saved on another address in Heap Memory
  // so the delete method in this scop will not cover that, we need to delete the player outside this scope
}

Player createStackPlayer() {
  Player player = Player("stack");
  return player;
  // the player object in this scope will extracted to a new Stack Address calling this method
  // so the end of this object will continue to the new address closing bracket '}'
}

Player* createHeapPlayer() {
  Player* player = new Player("heap");
  return player;
  // because pointer object need to be deleted manually
  // it's up to you when to delete it from Heap Memory
}

int main(){
  // when a variable, function/method, object are created inisde a body '{}'
  // after the opening bracket '{' they will be stored in Stack or Heap Memory
  // and after the closing bracket '}' they will be erased from ONLY the Stack Memory
  // to delete an object from Heap Memory, we should manually delete it

  // object lifetime in Stack Memory
  {
    Player player1 = Player("Azis");
  }

  // object lifetime in Heap Memory
  {
    Player* player2 = new Player("Ikrima");
    delete player2; // this is how to delete an object from Heap Memory
  }


  // same as using a function
  createPlayerStack();
  createPlayerHeap();

  // memory leak simulation
  cout << "\nMemory Leak" << endl;
  Player* playerPtr1;
  createPlayerStackPointer(playerPtr1);
  // cout << (*playerPtr1).nama << endl; // the data is random, because the address is not filled with this particular data anymore

  // Player* playerPtr2;                    //  THIS
  // createPlayerHeapPointer(playerPtr2);   //  IS A
  // cout << playerPtr2->nama << endl;      //  BAD
  // playerPtr2->nama = "Gobeng";           //  PRACTICE
  // cout << playerPtr2->nama << endl;      //  TO DO
  // delete playerPtr2;                     //  !!!

  // based on the OS you're using, in Linux Ubuntu the playerPtr2 strugling to find the player6
  // it will keep printing a blank spaces
  // so delete the playerPtr2 will solve the problem
  // but it will cause segmentation fault, so this is a bad practice
  
  cout << "\nReturned Object" << endl;
  Player returnedStackPlayer = createStackPlayer();
  cout << returnedStackPlayer.nama << endl;

  Player* returnedHeapPlayer = createHeapPlayer();
  cout << returnedHeapPlayer->nama << endl;
  delete returnedHeapPlayer;
  // see that returnedHeapPlayer deleted first before the returnedStackPlayer
  // even the returnedStackPlayer declared before returnedHeapPlayer
  // this happen because the returnedStackPlayer's delete event is at the end of this scope
  // and the returnedHeapPlayer deleting itself inside the same scope

  // the main issue is, we can't decide when to delete the object if it's stored in Stack Memory
  // instead, we must decide when to delete the object stored in Heap Memory
  // the benefit is we can control it so it doesn't overflowing
  return 0;
}
