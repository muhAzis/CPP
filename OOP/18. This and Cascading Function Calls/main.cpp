#include <iostream>
#include <string>

using namespace std;

class Player{
  private:
    string first_name;
    string sur_name;
    string last_name;

  public:
    Player() {
      first_name = "first name"; // implicit technique
      this->sur_name = "sur_name"; // explicit technique using pointer
      Player::last_name = "last_name"; // explicit technique using pointer/namespace
      (*this).last_name = "last_name"; // explicit technique using dereference 'this' to get dot(.) operator
      // deferencing 'this' will get the actual object, an not the pointer, so we can use dot(.) operator
    }

    // with '*this' method, we could use it to make "Cascading Funtion"
    // it is simply a function that return it's own object reference, or '*this'
    Player& setFirstName(const char* name) {
      this->first_name = name;
      return *this;
    }

    Player& setSurName(const char* name) {
      Player::sur_name = name;
      return *this;
    }

    Player& setLastName(const char* name) {
      (*this).last_name = name;
      return *this;
    }

    void display() {
      cout << "First name: " << first_name << endl;
      cout << "Sur name  : " << this->sur_name << endl;
      cout << "Last name : " << (*this).last_name << endl;
    }
};

int main(){
  Player* player1 = new Player();

  player1->setFirstName("Bogeng");
  player1->setSurName("Kyoryu");
  player1->setLastName("Subogeng");
  player1->display();

  // Cascading Funtion Call
  player1->setFirstName("Muhamad").setSurName("Abdul").setLastName("Azis");
  player1->display();

  Player player2 = Player();
  player2.setLastName("Saiddah").setFirstName("Ikrima").setSurName("Rai");
  // it doesn't matter what how the sequence are, because each function always returns the whole object reference
  player2.display();

  return 0;
}
