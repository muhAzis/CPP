#include <iostream>
#include <string>
#include "mahasiswa.hpp"

Mahasiswa::Mahasiswa(const char* name1, const char* name2) {
  this->namePublic = name1;
  this->namePrivate = name2; // can be done because private accessed from inside the object
}

void Mahasiswa::displayPublic() {
  std::cout << "Nama mhs public: " << this->namePublic << std::endl;
}

void Mahasiswa::displayPrivate() {
  std::cout << "Nama mhs private: " << this->namePrivate << std::endl;
}

void Mahasiswa::showFromPrivate() {
  this->displayPrivate();
}