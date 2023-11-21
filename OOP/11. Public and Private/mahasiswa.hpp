#ifndef __MAHASISWA
#define __MAHASISWA

#include <string>

class Mahasiswa{
  // you can even make more than one "public" or "private"
  // just for grouping purpose

  public: // can be accessed globally
    std::string namePublic;

  public:
    // constructor is always placed at public
    Mahasiswa(const char*, const char*);
    void displayPublic();
    void showFromPrivate();

  private: // can only be accessed by this object
    std::string namePrivate;

  private:
    void displayPrivate();

};

#endif