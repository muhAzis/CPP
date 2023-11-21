#include <iostream>
#include "variables.h"
using namespace std;

int main() {
  int n;
  cout << "Masukkan ukuran: ";
  cin >> n;
  
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= i; j++) {
      cout << "* ";
    }
    cout << endl;
  }

  cout << endl;

  for(int i = n; i >= 1; i--) {
    for(int j = 1; j <= i; j++) {
      cout << "* ";
    }
    cout << endl;
  }

  cout << endl;

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(j >= i) {
        cout << " *";
      } else {
        cout << "  ";
      }
    }
    cout << endl;
  }

  cout << endl;

  for(int i = n; i >= 1; i--) {
    for(int j = 1; j <= n; j++) {
      if(j >= i) {
        cout << " *";
      } else {
        cout << "  ";
      }
    }
    cout << endl;
  }

  cout << endl;

  for(int i = 1; i <= n; i++) {
    for(int k = n-1; k >= 1; k--) {
      if(k >= i) {
        cout << "  ";
      } else {
        cout << " *";
      }
    }

    for(int j = 1; j <= i; j++) {
      cout << " *";
    }
    cout << endl;
  }

  cout << endl;

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(j >= i) {
        cout << " *";
      } else {
        cout << "  ";
      }
    }

    for(int k = n; k > i; k--) {
      if(k >= i) {
        cout << " *";
      } else {
        cout << "  ";
      }
    }

    cout << endl;
  }

  cout << endl;

  for(int i = 1; i <= n; i++) {
    for(int k = n-1; k >= 1; k--) {
      if(k >= i) {
        cout << "  ";
      } else {
        cout << " *";
      }
    }

    for(int j = 1; j <= i; j++) {
      cout << " *";
    }
    cout << endl;
  }
  for(int i = 2; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(j >= i) {
        cout << " *";
      } else {
        cout << "  ";
      }
    }

    for(int k = n; k > i; k--) {
      if(k >= i) {
        cout << " *";
      } else {
        cout << "  ";
      }
    }

    cout << endl;
  }

  

  cin.get();
  return 0;
}