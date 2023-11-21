#include <iostream>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

struct Mahasiswa {
  int pk;
  string NIM;
  string nama;
  string jurusan;
};

int menuOption();
void checkDatabase(fstream &data);
void writeData(fstream &data, int pos, Mahasiswa &mhs);
int getDataSize(fstream &data);
Mahasiswa readData(fstream &data, int pos);
void addDataMhs(fstream &data); 
void displayDataMhs(fstream &data);

int main(){
  fstream data;
  checkDatabase(data);

  int userOpt = menuOption();
  char contChar;
  enum option{CREATE = 1, READ, UPDATE, DELETE, FINISH};

  while(userOpt != FINISH) {
    switch(userOpt) {
      case CREATE:
        cout << "Menambah data mahasiswa" << endl;
        addDataMhs(data);
        break;
      case READ:
        cout << "Menampilkan data mahasiswa" << endl;
        displayDataMhs(data);
        break;
      case UPDATE:
        cout << "Mengubah data mahasiswa" << endl;
        break;
      case DELETE:
        cout << "Menghapus data mahasiswa" << endl;
        break;
      default:
        cout << "Masukkan menu yang sesuai!" << endl;
        break;
    }

    lable_cont:

    cout << "Lanjutkan?(y/n): ";
    cin >> contChar;
    if(contChar == 'y' | contChar == 'Y') {
      userOpt = menuOption();
    } else if(contChar == 'n' | contChar == 'N') {
      break;
    } else {
      goto lable_cont;
    }
  }

  cout << "Program selesai" << endl;

  cin.get();
  return 0;
}

void checkDatabase(fstream &data) {
  data.open("data.bin", ios::out | ios::in | ios::binary);
  // check if file is exist
  if(data.is_open()) {
    cout << "Database ditemukan!" << endl;
  } else {
    cout << "Database tidak ditemukan, buat database baru" << endl;
    data.close();
    data.open("data.bin", ios::trunc | ios::out | ios::in | ios::binary);
  }
}

int menuOption() {
  // system("clear");
  int input;

  cout << "\nProgram CRUD data mahasiswa" << endl;
  cout << "=============================" << endl;
  cout << "1. Tambah data mahasiswa" << endl;
  cout << "2. Tampilkan data mahasiswa" << endl;
  cout << "3. Ubah data mahasiswa" << endl;
  cout << "4. Hapus data mahasiswa" << endl;
  cout << "5. Selesai" << endl;
  cout << "=============================" << endl;
  cout << "pilih [1-5]: " << endl;

  cin >> input;
  cin.ignore(numeric_limits<streamsize>::max(),'\n');
  return input;
}

void addDataMhs(fstream &data) {
  Mahasiswa mhs, lastMhs;
  // check data position
  int size = getDataSize(data);
  cout << "Banyak Mahassiswa saat ini: " << size << endl << endl;

  if(size == 0) {
    mhs.pk = 1;
  } else {
    lastMhs = readData(data, size);
    cout << "pk = " << lastMhs.pk << endl;
    mhs.pk = lastMhs.pk + 1;
  }

  cout << "Nama: ";
  getline(cin, mhs.nama);
  cout << "Jurusan: ";
  getline(cin, mhs.jurusan);
  cout << "NIM: ";
  getline(cin, mhs.NIM);

  writeData(data, size + 1, mhs);
}

void writeData(fstream &data, int pos, Mahasiswa &mhs) {
  data.seekp((pos - 1) * sizeof(Mahasiswa), ios::beg);
  data.write(reinterpret_cast<char*>(&mhs),sizeof(Mahasiswa));
}

Mahasiswa readData(fstream &data, int pos){
  Mahasiswa readMhs;
  data.seekg((pos - 1)*sizeof(Mahasiswa), ios::beg);
  data.read(reinterpret_cast<char*>(&readMhs), sizeof(Mahasiswa));

  return readMhs;
}

int getDataSize(fstream &data) {
  int start, end;
  data.seekp(0, ios::beg);
  start = data.tellg();
  data.seekg(0, ios::end);
  end = data.tellg();
  
  cout << "hasil cari : " << (end-start)/sizeof(Mahasiswa) << endl;
  return (end-start)/sizeof(Mahasiswa);
}

void displayDataMhs(fstream &data) {
  int size = getDataSize(data);
  Mahasiswa showMhs;
  cout << "no.\tpk.\tNIM.\tNama.\tJurusan." << endl;
  
  for(int i = 1; i <= size; i++) {
    showMhs = readData(data, i);
    cout << i << "\t";
    cout << showMhs.pk << "\t";
    cout << showMhs.NIM << "\t";
    cout << showMhs.nama << "\t";
    cout << showMhs.jurusan << endl;
  }
}