
#include <iostream>
#include <array>

const int M = 1020001;
const int L = 14;

std::array<std::array<char, L>, M> H;
std::array<unsigned long long, 128> charValues;

void initCharValues() {
  for (int i = 0; i < 128; i++) {
    charValues[i] = i < 4 ? i + 1 : 0;
  }
}

unsigned long long getkey(const char* word) {
  unsigned long long sum = 0, p = 1;
  for (int i = 0; word[i]; i++) {
    sum += p * charValues[word[i]];
    p *= 5;
  }
  return sum;
}

int h1(unsigned long long k) {
  return k % M;
}

int h2(unsigned long long k) {
  return 1 + (k % (M - 1));
}

void insert(const char* str) {
  unsigned long long key = getkey(str);
  for (int i = 0;; i++) {
    int h = (h1(key) + i * h2(key)) % M;
    if (H[h][0] == '\0') {
      std::strcpy(H[h].data(), str);
      return;
    }
  }
}

bool find(const char* str) {
  unsigned long long key = getkey(str);
  for (int i = 0;; i++) {
    int h = (h1(key) + i * h2(key)) % M;
    if (std::strcmp(H[h].data(), str) == 0) {
      return true;
    } else if (H[h][0] == '\0') {
      return false;
    }
  }
}

int main() {
  initCharValues();

  int NumOfCom;
  std::cin >> NumOfCom;

  for (int i = 0; i < M; i++) {
    H[i].fill('\0');
  }

  while (NumOfCom) {
    char com[9], word[14];
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