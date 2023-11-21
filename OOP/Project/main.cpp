#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>
#include <unistd.h>
#include <cstdlib>
#include "database.hpp"
#include "player.hpp"
#include "weapon.hpp"

using namespace std;

void in_battle(Player* &player, DataBase* &db) {
  system("clear");

  cout << "Fighting an opponent";
  for(int i = 0; i < 4; i++) {
    cout.flush();
    sleep(1);
    cout << ".";
  }
  cout.flush();

  player->fighting();
  cin.get();
}

void in_sleep(Player* &player) {
  system("clear");

  cout << "Zzzzzzzzzzzz";
  for(int i = 0; i < 4; i++) {
    cout.flush();
    sleep(1);
    cout << ".";
  }
  cout.flush();

  player->sleep();
  system("clear");
  cout << "Your health is full!" << endl;
  cin.get();
}

void in_save(Player* player, DataBase* &db) {
  system("clear");

  db->savePlayer(player);
  cout << "Saving your progress," << endl;
  cout << "please, do not invoke";
  for(int i = 0; i < 4; i++) {
    cout.flush();
    sleep(1);
    cout << ".";
  }
  cout.flush();

  system("clear");
  cout << "Your progress is saved!" << endl;
  cin.get();
}

int menu(DataBase* &db) {
  system("clear");
  int select;

  cout << "########################" << endl;
  cout << "##  THE LONE WARRIOR  ##" << endl;
  cout << "##        GAME        ##" << endl;
  cout << "########################" << endl;
  cout << "\n1. Start New Game" << endl;
  if(db->isEmpty()) {
    cout << "2. Exit Game\n" << endl;
    cout << "Your choice?(1-2): ";
  } else {
    cout << "2. Continue" << endl;
    cout << "3. Exit Game\n" << endl;
    cout << "Your choice?(1-3): ";
  }
  cin >> select;

  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  return select;
  
}

int inGameMenu() {
  int select;
  cout << "1. Battle (fight an enemy & increase stats)" << endl;
  cout << "2. Sleep  (heal your health)" << endl;
  cout << "3. Save   (saving your progress)" << endl;
  cout << "4. Exit   (exit the game)\n" << endl;
  cout << "Your choice?(1-4): ";
  cin >> select;

  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  return select;
}

void newGame(DataBase* &db) {
  system("clear");
  string name;
  char answer = ' ';
  std::string wpnName = "Beginner Sword";
  Weapon* weapon = new Weapon(wpnName, 50);

  cout << "Greetings, a brave warrior!" << endl;
  cout << "Before you begin to face your not very long," << endl;
  cout << "nor not very vast journey, please tell us your name!\n" << endl;
  repeat:
  if(answer != ' ') {
    cin.ignore();
  }
  cout << "Input your name:" << endl;
  getline(cin, name);

  system("clear");
  while(answer != 'y') {
    cout << name << ", is this name ok?\n" << endl;
    cout << "Your answer?(y/n): ";
    cin >> answer;
    if(answer == 'y' || answer == 'Y') {
      system("clear");

      cout << "So you are " << name << "." << endl;
      cout << "From now on, you will be facing evils and madness in this land." << endl;
      cout << "And here is \"" << weapon->getName() << "\" to help you on your journey." << endl;
      cout << "I wish you luck on your journey, brave warrior." << endl;
      cin.get();
      cin.ignore();

      Player* player = new Player(name);
      player->equipWeapon(weapon);
      db->savePlayer(player);

      break;
    } else if(answer == 'n' || answer == 'N') {
      system("clear");
      goto repeat;
      break;
    } else {
      cout << "Type (y/Y) for 'yes' or (n/N) for 'no'!";
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cin.get();
      system("clear");
    }

  }
}

void inGame(DataBase* &db) {

  Player* player = db->getPlayerData(db);
  enum menu{FIGHT = 1, SLEEP, SAVE, EXIT};

  restart:
  system("clear");
  cout << left << setw(35) << "===================================" << endl;
  cout << "||                               ||" << endl;
  cout << "|| " << left << setw(30) << player->getName() << "||" << endl;
  cout << "|| ----------------------------- ||" << endl;
  cout << "|| Level  : " << left << setw(21) << player->getLevel() << "||" << endl;
  cout << "|| Exp    : " << left << setw(4) << player->getExp() << "/" << left << setw(16) << player->getMaxExp() << "||" << endl;
  cout << "|| Health : " << left << setw(4) << player->getHealth() << "/" << left << setw(16) << player->getMaxHealth() << "||" << endl;
  cout << "||                               ||" << endl;
  cout << "|| Current Weapon :              ||" << endl;
  cout << "|| - \"" << left << setw(27) << player->getWeapon()->getName() + "\"" << "||" << endl;
  cout << "|| - Atk Power : " << left << setw(16) << player->getWeapon()->getPower() << "||" << endl;
  cout << "||                               ||" << endl;
  cout << "===================================\n" << endl;
  
  int userChoice = inGameMenu();

  switch(userChoice) {
    case FIGHT:
      in_battle(player, db);
      if(player->getHealth() <= 0) {
        db->createDb();
      } else {
        goto restart;
      }
      break;
    case SLEEP:
      in_sleep(player);
      goto restart;
      break;
    case SAVE:
      in_save(player, db);
      goto restart;
      break;
    case EXIT:
      char choice;
      cout << "Make sure you already saved your progress!" << endl;
      cout << "Any unsaved progress would not be loaded in the future!" << endl;
      repeat:
      cout << "Are you sure want to exit?(y/n): ";
      cin >> choice;
      if(choice == 'y' || choice == 'Y') {
        break;
      } else if(choice == 'n' || choice == 'N') {
        goto restart;
      } else {
        goto repeat;
      }
      break;
    default:
      cout << "Pick the right menu!" << endl;
      cin.get();
      goto restart;
      break;
  }
}

int main(){
  DataBase* db = new DataBase("player_data.txt");
  restart:
  enum menu2{START=1, CONTINUE, EXIT};

  if(!db->isExist()) {
    db->createDb();
  }

  int userChoice = menu(db);

  if(db->isEmpty()) {
    if(userChoice == 2) {
      userChoice = 3;
    }
  }

  while(userChoice != EXIT) {
    switch(userChoice) {
      case START:
        system("clear");
        cout << "Starting a new game";

        for(int i = 0; i < 4; i++) {
          cout.flush();
          sleep(1);
          cout << ".";
        }
        cout.flush();
        
        newGame(db);
        inGame(db);
        goto restart;
        break;
      case CONTINUE:
        system("clear");
        cout << "Continue from the last checkpoint!" << endl;
        cout << "Loading your data";

        for(int i = 0; i < 4; i++) {
          cout.flush();
          sleep(1);
          cout << ".";
        }
        cout.flush();

        inGame(db);
        goto restart;
        break;
      default:
        system("clear");
        cout << "Pick the right menu!!" << endl;
        cin.get();
        goto restart;
        break;
    }

    break;
  }
  return 0;
}
