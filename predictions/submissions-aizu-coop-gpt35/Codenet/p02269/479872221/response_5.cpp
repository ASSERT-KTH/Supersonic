#include <iostream>
#include <string>

#define M 1020001
#define L 14

bool hashTable[M] = {false};

int getnum(char ch) {
  if (ch == 'A') {
    return 1;
  } else if (ch == 'C') {
    return 2;
  } else if (ch == 'G') {
    return 3;
  } else {
    return 4;
  }
}

long long getkey(char word[]) {
  int sum = 0, p = 1, i;
  for (i = 0; word[i]; i++) {
    sum = sum + p * getnum(word[i]);
    p = p * 5;
  }
  return sum;
}

int h1(int k) {
  return k & (M - 1);
}

int h2(int k) {
  return 1 + (k % (M - 1));
}

void insert(char str[]) {
  int key, h, i;
  key = getkey(str);
  for (i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (!hashTable[h]) {
      hashTable[h] = true;
      return;
    }
  }
}

bool find(char str[]) {
  int key, h, i;
  key = getkey(str);
  for (i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (!hashTable[h]) {
      return false;
    }
  }
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
  };
  return 0;
}