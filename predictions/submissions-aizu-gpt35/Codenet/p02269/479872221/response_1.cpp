#include <iostream>
#include <cstring>
#include <string>
#define M 1020001
#define L 14
char H[M][L];
int getnum(char ch) {
  switch(ch) {
    case 'A': return 1;
    case 'C': return 2;
    case 'G': return 3;
    default: return 4;
  }
}
long long getkey(char word[]) {
  long long sum = 0, p = 1;
  for (int i = 0; word[i]; i++) {
    sum = sum + p * getnum(word[i]);
    p = p * 5;
  }
  return sum;
}
int h1(int k) { return k % M; }
int h2(int k) { return 1 + (k % (M - 1)); }
int insert(char str[]) {
  int key = getkey(str), h;
  for (int i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str) == 0) {
      return 0;
    }
    if (H[h][0] == '\0') {
      strcpy(H[h], str);
      return 1;
    }
  }
  return 0;
}
int find(char str[]) {
  int key = getkey(str), h;
  for (int i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str) == 0) {
      return 1;
    }
    if (H[h][0] == '\0') {
      return 0;
    }
  }
  return 0;
}
int main() {
  char com[9], word[14];
  int NumOfCom;
  std::cin >> NumOfCom;
  std::memset(H, 0, sizeof(H));
  while (NumOfCom--) {
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
  }
  return 0;
}