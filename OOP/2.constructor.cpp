#include <iostream>
#include <string>

using namespace std;

// basic Class
class Polos{
  public:
    string dataString;
    int dataInt;
};

// Class with constructor
class Mahasiswa{
  public:
    string nama;
    string NIM;
    string jurusan;
    double IPK;
    // this is constructor, calling the Class itself in a form of function (with/without params)
    Mahasiswa(string inNama, string inNIM, string inJurusan, double inIPK){
      // update the public variable(s) with the params given
      // to call the public variable, use identifier(namespace) that is the name of the Class
      // it works without calling the namespace too but make sure the params name doesn't match any public variables
      Mahasiswa::nama = inNama;
      Mahasiswa::NIM = inNIM;
      Mahasiswa::jurusan = inJurusan;
      Mahasiswa::IPK = inIPK;

      cout << "Nama    : " << Mahasiswa::nama << endl;
      cout << "NIM     : " << Mahasiswa::NIM << endl;
      cout << "Jurusan : " << Mahasiswa::jurusan << endl;
      cout << "IPK     : " << Mahasiswa::IPK << endl;
      cout << "-----------------------------" << endl;
    }
};

int main(){
  // calling the Class
  Mahasiswa mhs1 = Mahasiswa("Muh Abdul Azis", "431932", "Tekins", 3.34);
  Mahasiswa mhs2 = Mahasiswa("Ikrima Rai Saiddah", "431956", "Trik", 3.56);
  return 0;
}
