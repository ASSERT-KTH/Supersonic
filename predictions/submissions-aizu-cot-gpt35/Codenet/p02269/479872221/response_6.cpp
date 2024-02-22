#include <iostream>
#include <cstring>

#define M 1020001

char H[M][14];

int getnum(char ch) {
  switch (ch) {
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
  long long sum = 0;
  int p = 1;
  for (int i = 0; word[i]; i++) {
    sum = sum + (p * getnum(word[i]));
    p = p << 2;
  }
  return sum;
}

int h1(int k) { return k % M; }

int h2(int k) { return 1 + (k % (M - 1)); }

int insert(const char* str) {
  int key = getkey(str);
  for (int i = 0;; i++) {
    int h = (h1(key) + (i * h2(key))) % M;
    if (H[h][0] == '\0') {
      std::strcpy(H[h], str);
      return 1;
    } else if (std::strcmp(H[h], str) == 0) {
      return 0;
    }
  }
}

int find(const char* str) {
  int key = getkey(str);
  for (int i = 0;; i++) {
    int h = (h1(key) + (i * h2(key))) % M;
    if (H[h][0] == '\0') {
      return 0;
    } else if (std::strcmp(H[h], str) == 0) {
      return 1;
    }
  }
}

int main() {
  char com[9], word[14];
  int NumOfCom;
  std::cin >> NumOfCom;
  
  for (int i = 0; i < M; i++)
    H[i][0] = '\0';
  
  while (NumOfCom) {
    std::cin >> com >> word;
    if (com[0] == 'i') {
      insert(word);
    } else {
      if (find(word)) {
        std::cout << "yes\n";
      } else {
        std::cout << "no\n";
      }
    }
    NumOfCom--;
  }
  
  return 0;
}