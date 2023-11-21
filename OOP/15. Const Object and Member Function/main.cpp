#include <iostream>
#include <string>

using namespace std;

class Hero{
  public:
    string name;

  public:
    Hero(const char* name) {
      this->name = name;
    }

    // setter
    void setName(const char* name) {
      this->name = name;
    }

    // getter
    string getName() const {
      return this->name;
    }

    void display() const {
      cout << "Hero name: " << this->name << endl;
    }
};

int main() {
  Hero* hero1 = new Hero("Bogeng"); // hero1 is not a constant object
  hero1->display();
  hero1->name = "Gobeng"; // and because attribute 'name' is a public member, this can be done
  hero1->display(); // even if hero1 is not a constant object, it can call constant method
  hero1->setName("Borogegeng");
  hero1->display();
  cout << hero1->getName() << endl;

  const Hero* hero2 = new Hero("Matilda"); // hero2 is a constant object
  hero2->display(); // this method can be called only if the method is a constant member too
  // hero2->name = "Tildama"; // this can't be done even 'name' is a public member because hero2 is constant
  // hero2->setName("Tildama"); // this can't be done because 'setName' is not a constant method
  cout << hero2->getName() << endl; // this can be done because 'getName' is a constant method

  // conclusion: const object can only call constant methods too, but normal object can call any member method
  return 0;
} 