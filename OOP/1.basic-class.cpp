#include <iostream>
#include <string>

using namespace std;

// declare a Class template
class Mahasiswa{
  // public access
  public:
    string nama;
    string NIM;
    string jurusan;
    double IPK;
};

int main(){
  Mahasiswa mhs1, mhs2;
  mhs1.nama = "Muh Abdul Azis";
  mhs1.NIM = "431932";
  mhs1.jurusan = "Tekins";
  mhs1.IPK = 3.34;
  mhs2.nama = "Ikrima Rai Saiddah";
  mhs2.NIM = "431956";
  mhs2.jurusan = "Trik";
  mhs2.IPK = 3.56;

  cout << "Mahasiswa Pertama:" << endl;
  cout << "- Nama    : " << mhs1.nama << endl;
  cout << "- NIM     : " << mhs1.NIM << endl;
  cout << "- Jurusan : " << mhs1.jurusan << endl;
  cout << "- IPK     : " << mhs1.IPK << endl;
  cout << endl;
  cout << "Mahasiswa Kedua:" << endl;
  cout << "- Nama    : " << mhs2.nama << endl;
  cout << "- NIM     : " << mhs2.NIM << endl;
  cout << "- Jurusan : " << mhs2.jurusan << endl;
  cout << "- IPK     : " << mhs2.IPK << endl;
  return 0;
}
