#include <iostream>
#include <string>

#define M 1020001
#define L 14

std::string H[M];

int getnum(char ch) {
  switch(ch) {
    case 'A':
      return 1;
    case 'C':
      return 2;
    case 'G':
      return 3;
    default:
      return 4;
  }
}

long long getkey(const char* word) {
  int sum = 0, p = 1;
  while (*word) {
    sum = sum + p * getnum(*word);
    p = p * 5;
    word++;
  }
  return sum;
}

int h1(int k) { return k % M; }
int h2(int k) { return 1 + (k % (M - 1)); }

int insert(const std::string& str) {
  int key, h, i;
  key = getkey(str.c_str());
  for (i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (H[h].empty()) {
      H[h] = str;
      return 1;
    } else if (H[h] == str) {
      return 0;
    }
  }
  return 0;
}

int find(const std::string& str) {
  int key, h, i;
  key = getkey(str.c_str());
  for (i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (H[h].empty()) {
      return 0;
    } else if (H[h] == str) {
      return 1;
    }
  }
  return 0;
}

int main() {
  std::string com, word;
  int NumOfCom;
  std::cin >> NumOfCom;
  while (NumOfCom) {
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
    NumOfCom--;
  }
  return 0;
}