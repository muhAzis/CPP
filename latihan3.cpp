#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <regex>
#include <array>

bool isPrime(int &num) {
  for(int i = 2; i < num; i++) {
    if(num%i == 0) {
      return 0;
    }
  }
  
  return 1;
}

int main(){
  // std::string str = "what time are we climbing up the volcano";
  // std::string s;
  // std::stringstream text(str);
  // std::vector<std::string> words;
  // std::vector<int> cals;
  
  // while(getline(text, s, ' ')) {
  //   words.push_back(s);
  // }

  // for(std::string word : words) {
  //   int count = 0;
  //   for(char let : word) {
  //     count += int(let) - 96;
  //   }
  //   cals.push_back(count);
  // }

  // std::vector<int>::iterator pos = std::find(cals.begin(), cals.end(), *max_element(cals.begin(), cals.end()));
  // std::cout << words[pos - cals.begin()] << std::endl;
  // std::string num1 = "123";
  // std::string num2 = "456";

  // std::cout << "num1 : " << stoi(num1) << std::endl;
  // std::cout << "num2 : " << stoi(num2) << std::endl;
  // std::cout << "num1 + num2 : " << stoi(num2) + stoi(num1) << std::endl;
  // std::string a = "746289";
  // std::string b = "482745";

  // std::string res;
  // int lap = 0;
  // int a_size = a.size();
  // int b_size = b.size();
  
  // for(int i = (a_size >= b_size ? a_size : b_size)-1; i >= 0; i--) {
  //   int sum = (int(a[i])-48) + (int(b[i])-48) + lap;
  //   lap = 0;
    
  //   if(sum >= 10) {
  //     if(i == 0) {
  //       std::string x = std::to_string(sum);
  //       std::reverse(x.begin(), x.end());
  //       res += x;
  //     } else {
  //       res += std::to_string(sum % 10);
  //       lap++;
  //     }
  //   } else {
  //     res += std::to_string(sum);
  //   }

  // }

  // std::reverse(res.begin(), res.end());

  // std::cout << "result : " << res << std::endl;

  // int n = 15;
  // std::array<int, 3> result;
  // std::vector<int> emirps;

  // // if(n < 11) {
  // //   result[0] = 0;
  // //   result[1] = 0;
  // //   result[2] = 0;
  // // }
  
  // for(int i = 11; i <= n; i++) {
  //   bool state1 = isPrime(i);
  //   if(state1) {
  //     std::string sState1 = std::to_string(i);
  //     std::reverse(sState1.begin(), sState1.end());

  //     int rState1 = stoi(sState1);
  //     bool state2 = isPrime(rState1);
      
  //     if(state2 && i != rState1) {
  //       emirps.push_back(i);
  //     }
  //   }
  // }

  // if(emirps.size()) {
  //   result[0] = emirps.size();
  //   result[1] = emirps[result[0]-1];
  //   result[2] = std::accumulate(emirps.begin(), emirps.end(), 0);
  // } else {
  //   result[0] = 0;
  //   result[1] = 0;
  //   result[2] = 0;
  // }

  // // jump:
  // for(int item : result) {
  //   std::cout << "result : " << item << std::endl;
  // }
  
  std::cout << char(tolower('c')) << std::endl;

  return 0;
}
