#include <iostream>
#include <unordered_set>

#define M 1020001
#define L 14

std::unordered_set<long long> H;

int getnum(char ch) {
  static const int numTable[] = {0, 1, 2, 3, 4};
  return numTable[ch - 'A'];
}

long long getkey(const char* word) {
  long long sum = 0, p = 1;
  for (int i = 0; word[i]; i++) {
    sum += p * getnum(word[i]);
    p *= 5;
  }
  return sum;
}

int insert(const char* str) {
  long long key = getkey(str);
  if (H.count(key) == 0) {
    H.insert(key);
    return 1;
  }
  return 0;
}

int find(const char* str) {
  long long key = getkey(str);
  return H.count(key);
}

int main() {
  char com[9], word[14];
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