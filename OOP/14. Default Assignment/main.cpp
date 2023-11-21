#include <iostream>
#include <string>

using namespace std;

class Hero{
  private:
    string name;
    double health;
    double power;

  public:
    Hero(const char* name, double health = 100, double power = 150) { // declare default value straight to the attribute's declaration
      this->name = name;
      this->health = health;
      this->power = power;
    }

    void display() {
      cout << "Player Info" << endl;
      cout << "- Name\t: " << this->name << endl;
      cout << "- HP\t: " << this->health << endl;
      cout << "- Power\t: " << this->power << endl;
    }
};

int main() {
  Hero* hero1 = new Hero("Sakatonik Bangga"); // if we aren't declaring the 'health' parameter and 'power'
  hero1->display();
  // so the 'health' will automatically filled with 100 and 'power' with 150 when Hero created

  Hero* hero2 = new Hero("Rin Sakuragi", 150.5, 276.3); // but if we declare all the params
  hero2->display();
  // it will everride the default value with the declared value

  return 0;
}