#include <iostream>
#include <string>
#include "mahasiswa.hpp"

using namespace std;

int main() {
  Mahasiswa* mhs1 = new Mahasiswa("Naruto", "Hinata");
  mhs1->displayPublic(); // can be done because the method is public
  // mhs1->displayPrivate(); // can't be done because the method is prvate

  mhs1->showFromPrivate();
  // can be done because the method stored in private is called with a method
  // stored in public, and just call the public one
  return 0;
}