#include <iostream>
#include <string>

using namespace std;

class DenganConstructor{
  public:
    string data;

    DenganConstructor(const char* data) {
      DenganConstructor::data = data;
    }

    void show() {
      cout << "ini " << DenganConstructor::data << endl;
    }
};

class TanpaConstructor{
  public:
    string data;

  void show() {
    cout << "ini " << TanpaConstructor::data << endl;
  }
};

int main(){
  // 1. creating object without a constructor
  TanpaConstructor obj1;
  obj1.data = "object 1 tanpa constructor";
  obj1.show();

  // 2. creating object with a constructor
  DenganConstructor obj2 = DenganConstructor("object 2 dengan constructor");
  obj2.show();
  // or
  DenganConstructor obj3("object 3 dengan constructor");
  obj3.show();

  // 3. creating object in the 'heap memory' instead of 'stack memory'
  DenganConstructor* obj4 = new DenganConstructor("object 4 pada heap memory");
  // calling the methods inside the reference object
  (*obj4).show(); //using dereference method, or
  obj4->show();   //using arrow operator (mapping the object's member methods/fucntions & attributes)
  cout << obj4->data << endl; // using arrow operator, we can also call the member variables/attributes

  // without referencing the object, we can't declare the constructor explicitly, exp:
  // 
  // DenganConstructor obj5;
  // obj5 = DenganConstructor("object 5");
  // 
  // it will cause an error, instead we use reference
  DenganConstructor* obj5;
  obj5 = new DenganConstructor("object 5 dengan constructor explisit");
  obj5->show();

  return 0;
}
