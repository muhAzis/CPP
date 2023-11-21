#include <iostream>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

class Mahasiswa{
  public:
    string nama;
    string NIM;
    string jurusan;
    double IPK;

    Mahasiswa(string inNama, string inNIM, string inJurusan, double inIPK){
      Mahasiswa::nama = inNama;
      Mahasiswa::NIM = inNIM;
      Mahasiswa::jurusan = inJurusan;
      Mahasiswa::IPK = inIPK;
    }

    string stringify() {
      return ("\n" + nama + "," + NIM + "," + jurusan + ',' + to_string(IPK));
    }
};

class dataBase{
  public:
    ifstream in;
    ofstream out;
    string fileName;

    dataBase(const char* fileName) {
      dataBase::fileName = fileName;
    }

    void save(Mahasiswa data) {
      dataBase::out.open(dataBase::fileName, ios::app);
      dataBase::out << data.stringify();
      dataBase::out.close();
    }

    void showAll() {
      dataBase::in.open(dataBase::fileName, ios::in);
      string nama, nim, jurusan, ipk;
      int index = 1;
      
      cout << "No.\t" << "Nama\t\t\t" << "NIM\t\t" << "Jurusan\t\t\t" << "IPK" << endl;

      while(!dataBase::in.eof()) {
        getline(dataBase::in, nama, ',');
        getline(dataBase::in, nim, ',');
        getline(dataBase::in, jurusan, ',');
        getline(dataBase::in, ipk, '\n');

        cout << index;
        cout << "\t" << nama;
        cout << "\t\t" << nim;
        cout << "\t\t" << jurusan;
        cout << "\t\t\t" << ipk << "/4.00" << endl;
        index++;
      }
      dataBase::in.close();
    }
};

int menuSelect();
void addData(dataBase &db);

int main(){
  dataBase db = dataBase("data.txt");
  restart:
  int select = menuSelect();
  enum menu{ADD = 1, READ, FINISH};

  while(select != FINISH) {
    switch(select) {
      case ADD:
        system("clear");
        addData(db);
        break;
      case READ:
        system("clear");
        db.showAll();
        break;
      default:
        cout << "Masukkan pilihan yang sesuai!" << endl;
        cin.get();
        goto restart;
        break;
    }

    repeat:
    cout << "\nApakah anda ingin melanjutkan?(y/n): ";
    char choice;
    cin >> choice;
    if(choice == 'y' || choice == 'Y') {
      goto restart;
    } else if(choice == 'n' || choice == 'N') {
      break;
    } else {
      goto repeat;
    }
  }
  
  return 0;
}

int menuSelect() {
  system("clear");
  int select;

  cout << "PROGRAM DATABASE MAHASISWA" << endl;
  cout << "============ MENU ===========" << endl;
  cout << "1. Tambah data mahasiswa    -" << endl;
  cout << "2. Tampilkan data mahasiswa -" << endl;
  cout << "3. Keluar                   -" << endl;
  cout << "-----------------------------" << endl;
  cout << "Pilih menu[1-3]: ";
  cin >> select;

  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  return select;
}

void addData(dataBase &db) {
  string nama, NIM, jurusan;
  double IPK;
  cout << "Masukkan Data Mahasiswa" << endl;
  cout << "-----------------------" << endl;
  cout << "Nama    : ";
  getline(cin, nama);
  cout << "NIM     : ";
  getline(cin, NIM);
  cout << "Jurusan : ";
  getline(cin, jurusan);
  cout << "IPK     : ";
  cin >> IPK;

  Mahasiswa mhs = Mahasiswa(nama, NIM, jurusan, IPK);
  db.save(mhs);
}