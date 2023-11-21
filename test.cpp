#include <iostream>
using namespace std;

// class ClassA {
//   int * pA;
//   public:
//     ClassA() {
//       pA = new int[10];
//     }
//     ~ClassA() {
//       delete [] pA;
//     }
// };

// int main() {
//   ClassA * a = new ClassA[256];
//   delete[] a;
//   return 0;
// }

// class Animal {
//   public:
//     void Eat(){}
//     void Sleep(){}
// };

// class Cat : public Animal {
//   public:
//     void Meow(){}
// };

// class Dog : public Animal {
//   public:
//     void Bow_wow(){}
// };

// void main() {
//   vector<Animal*> animals;
//   for(int i=0; i<10; i++) {
//     if(i%2) animals.push_back(new Dog);
//     else animals.push_back(new Cat);
//   }
//   for(int i=1; i<10; i++) {
//     if(i%2) ((Cat*)(animals[i]))->Meow();
//     else ((Dog*)(animals[i]))->Bow_Wow();
//   }
// }

class App {
  int x;
  public:
    void Init() {printf("\nInit");}
    void Calculate() {printf("\nCalculate");}
    void Clear() {printf("\nFress");}
};

int main() {
  App ob;
  void (App:: *v[])() = {&App::Init, &App::Calculate, $App::Clear};
  
}

// float medie(float a, float b) {
//   return  1.0/2.0 *(a+b);
// }

// #define Display(x) printf(#x"=%s", x)

// class App {
//   int x;
//   public:
//     void Init() {cout<<x;}
// };

// int main() {
//   App ob;
//   ob.Init();
//   return 0;
// }