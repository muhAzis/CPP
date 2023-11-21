#include <iostream>
#include <string>

using namespace std;

class Mahasiswa{
  public:
    string nama;
    double IPK;

    // this constructor is considerred a 'Method'/function too
    Mahasiswa(string nama, double IPK){
      Mahasiswa::nama = nama;
      Mahasiswa::IPK = IPK;
    }

    // making a Method is just like declaring a normal function
    void tampilkanData() {
      cout << "Nama : " << Mahasiswa::nama << endl;
      cout << "IPK  : " << Mahasiswa::IPK << endl;
      cout << "--------------------------" << endl;
    }

    // Method with params
    void ubahNama(const char* newNama) {
      Mahasiswa::nama = newNama;
    }

    // Method that returns value
    string getNama() {
      return Mahasiswa::nama;
    }

    double getIPK() {
      return Mahasiswa::IPK;
    }

    // Methods using params and returns value
    // Using 'const' if we pass a literal value so the value doesn't change
    double katrolIPK(const double &nilai) {
      return Mahasiswa::IPK + nilai;
    }
};

int main(){
  Mahasiswa mhs1 = Mahasiswa("Muh Abdul Azis", 3.34);
  Mahasiswa mhs2 = Mahasiswa("Ikrima Rai Saiddah", 3.56);

  // calling the Method inside the Class
  // (class-object).<method-name(params)>;
  mhs1.tampilkanData();
  mhs2.tampilkanData();

  mhs1.ubahNama("Muhamad Abdul Azis");
  // the first data type of 'name' is 'string', why change it to 'const char*'?
  // 'string' is a library, wich include so much function in it that we don't need in this particular Method
  // and because the input is literal, so using 'const char*' is much eficient than using 'string'
  // in memory consumption
  // !!CONCLUSION!!
  // 
  // 'string' = 'const char*'
  // 
  mhs1.tampilkanData();

  // calling Methods to get values
  string nama1 = mhs1.getNama();
  double IPK1 = mhs1.getIPK();
  cout << "Nama 1 : " << nama1 << endl;
  cout << "IPK 1  : " << IPK1 << endl;
  // or
  cout << "Nama 2 : " << mhs2.getNama() << endl;
  cout << "IPK 2  : " << mhs2.getIPK() << endl;
  cout << "--------------------------" << endl;

  // calling Methods passing values and get response value
  cout << "IPK 1, before: " << mhs1.getIPK() << ", after: " << mhs1.katrolIPK(0.5) << endl;
  cout << "IPK 2, before: " << mhs2.getIPK() << ", after: " << mhs1.katrolIPK(0.32) << endl;

  return 0;
}
