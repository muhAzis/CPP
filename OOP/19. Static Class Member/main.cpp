#include <iostream>
#include <string>

using namespace std;

class Hero{
  private:
    string name;
    double health;

  public:
    static int count; // static only lives inside a class object, can only accessed from outsid it's scope

    Hero(const char* name, double health) {
      this->name = name;
      this->health = health;
      count++;
    }

    // destructor
    ~Hero() {
      count--;
      cout << this->name << " is deleted" << endl;
    }

    void display() {
      cout << "name\t: " << this->name << endl;
      cout << "health\t: " << this->health << endl;
    }

};

int Hero::count = 0; // state a value of static attribute

int main(){
  Hero hero1 = Hero("Granger", 100);
  hero1.display();
  cout << "Hero Count from object: " << hero1.count << endl;
  cout << "Hero Count from class : " << Hero::count << endl;
  cout << "---------------------------" << endl;

  Hero hero2 = Hero("Layla", 100);
  hero2.display();
  cout << "Hero Count from object: " << hero2.count << endl;
  cout << "Hero Count from class : " << Hero::count << endl;
  cout << "---------------------------" << endl;

  Hero* hero3 = new Hero("Roger", 100);
  hero3->display();
  cout << "Hero Count from object: " << hero3->count << endl;
  cout << "Hero Count from class : " << Hero::count << endl;
  cout << "---------------------------" << endl;

  Hero* hero4 = new Hero("Kimmy", 100);
  hero4->display();
  cout << "Hero Count from object: " << hero4->count << endl;
  cout << "Hero Count from class : " << Hero::count << endl;
  cout << "---------------------------" << endl;

  delete hero3;
  cout << "Hero Count from class : " << Hero::count << endl;
  cout << "---------------------------" << endl;
  delete hero4;
  cout << "Hero Count from class : " << Hero::count << endl;

  // see how the count is incrementing every new Hero object are created
  // and decrementing when an object are deleted
  // doesn't matter from which object we access it, they will all be the same value
  // so it's not a unique attributes of an object

  return 0;
}
