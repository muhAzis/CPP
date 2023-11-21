#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<Clock>;

class Kosong{
  public:
    int data() {
      return 1;
    }
};

class Isi{
  public:
    int dataInt1;
    int dataInt2;
    double dataDouble;
};

class IsiDenganMethod{
  public:
    int dataInt1;       // 4 bytes
    int dataInt2;       // 4 bytes
    double dataDouble;  // 8 bytes
    string dataString;  // 32 bytes

    void fill(int data1) {
      IsiDenganMethod::dataInt1 = data1;
    }
};

class Mahasiswa{
  public:
    string nama;

    Mahasiswa(const char* nama) {
      Mahasiswa::nama = nama;
    }
};

int main(){
  // showing memory usage of empty Class
  cout << "Alokasi Class kosong : " << sizeof(Kosong) << endl;
  // it cost only 1 byte

  // showing memory usage of filled Class
  cout << "Alokasi Class isi : " << sizeof(Isi) << endl;
  // it cost the sum of all the members data type size
  // there are int(4 bytes) x2 and a double(8 bytes)
  // so the total memory used is 16 bytes

  // showing memory usage of filled Class with methods inside
  cout << "Alokasi Class isi dengan method : " << sizeof(IsiDenganMethod) << endl;
  // so the data inside the method's attribute aren't counted as part of the Class's size
  // it only count the local variables and methods

  // Address memory
  cout << "\nAddress in Stack Memory" << endl;
  // Stack memory is a limited size of memory that our program have
  // so when it filled up and cause a memory leak we call it as 'Stack Overflow'
  // Stack memory saves data sequentially based on the sequence of declaring data
  string a,b;
  Mahasiswa mhs1 = Mahasiswa("Azis");
  string c,d;
  cout << "Address string a: " << &a << endl; 
  cout << "Address string b: " << &b << endl;
  cout << "Address mhs1    : " << &mhs1 << endl; 
  cout << "Address string c: " << &c << endl; 
  cout << "Address string d: " << &d << endl;
  // the memory of the 4 string above are saved in sequence as the declaration sequence

  cout << "\nAddress in Heap Memory" << endl;
  // Heap memory is a bigger size of memory using the free memory of our device
  // so it will blend with another programs memory in out device
  string e,f;
  Mahasiswa* mhs2 = new Mahasiswa("Azis");
  string g,h;
  cout << "Address string e: " << &e << endl; 
  cout << "Address string f: " << &f << endl;
  cout << "Address mhs2 ref: " << &mhs2 << endl; 
  cout << "Address mhs2 ptr: " << mhs2 << endl; 
  cout << "Address string g: " << &g << endl; 
  cout << "Address string h: " << &h << endl;
  // notice that the reference variable of mhs2 still saved in the Stack Memory
  // but the actual object of mhs2 is saved in Heap Memory, so the memory of
  // pointer mhs2 is different than the other data

  // Time taken to create an object using Stack and Heap Memory
  TimePoint *tStackStart = new TimePoint();
  TimePoint *tStackEnd = new TimePoint();
  TimePoint *tHeapStart = new TimePoint();
  TimePoint *tHeapEnd = new TimePoint();

  *tStackStart = Clock::now();
  Mahasiswa mhs3 = Mahasiswa("Ikrima");
  *tStackEnd = Clock::now();
  cin.get();
  *tHeapStart = Clock::now();
  Mahasiswa* mhs4 = new Mahasiswa("Azis");
  *tHeapEnd = Clock::now();

  chrono::duration<double> durasi1 = *tStackEnd - *tStackStart;
  chrono::duration<double> durasi2 = *tHeapEnd - *tHeapStart;
  cout << "Durasi pembuatan object di Stack Memory: " << durasi1.count() << endl;
  cout << "Durasi pembuatan object di Heap Memory : " << durasi2.count() << endl;
  // the time needed to create an object in Stack Memory is way quicker than in Heap Memory (depends on your disk speed and space)
  // the only problem using Stack Memory is when the memory geting full so it will collapse
  
  return 0;
}
