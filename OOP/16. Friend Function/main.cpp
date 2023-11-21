#include <iostream>
#include <string>

using namespace std;

// 'friend' is a keyword that makes a function/method can have access to public
// or non-public member like private

class IntelHero; // we need this because StrengthHero need it to be declared first

class StrengthHero{
  private:
    string name;
    double health;

  public:
    StrengthHero(const char* name) {
      this->name = name;
      this->health = 100;
    }

    friend bool compare(const StrengthHero& hero1, const IntelHero& hero2); // declared globally
    friend bool compare(const IntelHero& hero1, const StrengthHero& hero2); // declared in IntelHero
    // because compare() have 'friend' keyword with IntelHero object
    // so it can be declared in either one
};

class IntelHero{
  private:
    string name;
    double health;

  public:
    IntelHero(const char* name) {
      this->name = name;
      this->health = 50;
    }

    friend bool compare(const StrengthHero& hero1, const IntelHero& hero2);
    friend bool compare(const IntelHero& hero1, const StrengthHero& hero2) {
      cout << "Compare function in global scope" << endl;
      return hero1.health > hero2.health;
    }
};

bool compare(const StrengthHero& hero1, const IntelHero& hero2) {
  cout << "Compare function in global scope" << endl;
  return hero1.health > hero2.health;
}

int main(){
  StrengthHero hero1 = StrengthHero("Bogeng");
  IntelHero hero2 = IntelHero("Matilda");

  cout << compare(hero1, hero2) << endl;
  cout << compare(hero2, hero1) << endl;
  // 'friend' works like connector to two or more objects with the same method
  return 0;
}
