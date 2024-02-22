#include <iostream>
#include <unordered_map>
#include <string>
#define M 1020001

std::unordered_map<long long, std::string> H;

int getnum(char ch) {
  switch(ch) {
    case 'A': return 1;
    case 'C': return 2;
    case 'G': return 3;
    case 'T': return 4;
    default: return 0;
  }
}

long long getkey(const std::string& word) {
  int sum = 0, p = 1;
  for (const auto& ch : word) {
    sum = sum + p * getnum(ch);
    p = p * 5;
  }
  return sum;
}

bool insert(const std::string& str) {
  long long key = getkey(str);
  if (H.count(key) && H[key] == str) {
    return false;
  } else {
    H[key] = str;
    return true;
  }
}

bool find(const std::string& str) {
  long long key = getkey(str);
  return H.count(key) && H[key] == str;
}

int main() {
  std::string com, word;
  int NumOfCom;
  std::cin >> NumOfCom;
  while (NumOfCom--) {
    std::cin >> com >> word;
    if (com[0] == 'i') {
      insert(word);
    } else {
      if (find(word)) {
        std::cout << "yes" << std::endl;
      } else {
        std::cout << "no" << std::endl;
      }
    }
  };
  return 0;
}