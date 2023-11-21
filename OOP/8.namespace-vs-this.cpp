#include <iostream>
#include <string>

using namespace std;

// data member
class ClassTypes{
  public:
    string dataStr;
    double dataDbl;
    double m_dataDbl;

    ClassTypes(const char* dataStr, double dataDbl) {
      // first way to declare member variables inside an object
      // using Namespace::member_var = input_var
      ClassTypes::dataStr = dataStr;

      // second way to declare member variables inside an object
      // using this->member_var = input_var
      this->dataDbl = dataDbl;
      // "this" refer to the object itself, works just the same as Namespaces
      // it is a pointer to the object
      // the Arrow Function "->" refers to get a member from a pointer data

      // third way to declare member variables inside an object
      // simply using different naming
      m_dataDbl = dataDbl;
    }
};

class Player{
  public:
    string name;
    double power;
    double health;

    Player(const char* name, double power) {
      // calling method using Namespace
      Player::setName(name);
      // calling method using this
      this->setPower(power);
    }

    void setName(const char* name) {
      this->name = name;
    }

    void setPower(double power) {
      this->power = power;
    }

    // creating a template method
    void setHealth(int);
};

// Namespace useful when we want to declare an object member method/function
// outside of the object itself, so it will refer to which object desired
void Player::setHealth(int health) {
  // "this" will work as well here, and Namespace also
  this->health = health;
}

int main(){
  ClassTypes* obj1 = new ClassTypes("Object 1", 0.05);
  cout << obj1->dataStr << endl;
  cout << obj1->dataDbl << endl;
  cout << obj1->m_dataDbl << endl;

  Player* player1 = new Player("Azis", 7.55);
  cout << player1->name << endl;
  cout << player1->power << endl;
  player1->setHealth(100);
  cout << player1->health << endl;

  return 0;
}
