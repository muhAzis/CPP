#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

void filter(string &result, int &rep, char high_let, char mid_let, char low_let) {
  if(rep / 9 == 1){
    result += low_let;
    result += high_let;
    rep -= 9;
  } else if(rep / 5 == 1) {
    result += mid_let;
    rep -= 5;
  } else if(rep / 4 == 1) {
    result += low_let;
    result += mid_let;
    rep -= 4;
  }

  if(rep > 0) {
    for(int i = 0; i < rep; i++) {
      result += low_let;
    }
  }
}

int main(){
  int number = 1943;
  int rep;
  string result;
  
  while(number > 0) {
    if(number >= 1000) {
      rep = number/1000;
      for(int i = 0; i < rep; i++) {
        result += 'M';
      }
      number -= 1000 * rep;
    } else if(number < 1000 && number >= 100) {
      rep = number/100;
      filter(result, rep, 'M', 'D', 'C');
      number -= 100 * (number/100);
    } else if(number < 100 && number >= 10) {
      rep = number/10;
      filter(result, rep, 'C', 'L', 'X');
      number -= 10 * (number/10);
    } else {
      rep = number;
      filter(result, rep, 'X', 'V', 'I');
      number -= 1 * (number/1);
    }
  }

  cout << result << endl;
  
  cin.get();
  return 0;
}
