#include <iostream>
#include <string>

using namespace std;

class PersegiPanjang;

// 'friend' keyword only works one-way, so it should be declared in both object
class Persegi{
  friend class PersegiPanjang; // PersegiPanjang is a friend of Persegi
  private:
    double sisi;

  public:
    Persegi(double sisi) {
      this->sisi = sisi;
    }

    double luas() {
      return this->sisi * this->sisi;
    }

    bool isLonger(const PersegiPanjang &kotak);
};

class PersegiPanjang{
  friend class Persegi; // Persegi is a friend of PersegiPanjang
  private:
    double panjang;
    double lebar;

  public:
    PersegiPanjang(double panjang, double lebar) {
      this->panjang = panjang;
      this->lebar = lebar;
    }

    double luas() {
      return this->panjang * this->lebar;
    }

    bool isLonger(const Persegi &persegi) {
      bool isTrue = this->panjang > persegi.sisi; // PersegiPanjang can access Persegi's private member
      return isTrue;
    }
};

// this declared here because PersegiPanjang declared after Persegi
bool Persegi::isLonger(const PersegiPanjang &kotak) {
  bool isTrue = this->sisi > kotak.panjang; // Persegi can access PersegiPanjang's private member
  return isTrue;
}

int main(){
  Persegi persegi = Persegi(6);
  PersegiPanjang kotak = PersegiPanjang(5,10);

  cout << "Luas persegi: " << persegi.luas() << endl;
  cout << "Luas kotak: " << kotak.luas() << endl;
  bool logika1 = kotak.isLonger(persegi);
  bool logika2 = persegi.isLonger(kotak);
  cout << "Kotak lebih panjang dari Persegi : " << logika1 << endl;
  cout << "Persegi lebih panjang dari Kotak : " << logika2 << endl;
  return 0;
}
