#include <iostream>
#include <cstring>
#define M 1020001
#define L 14
char H[M][L];
const int powers[] = {1, 5, 25, 125, 625};
int getkey(char* word) {
  int sum = 0;
  for (int i = 0; i < L; i++) {
    sum += (word[i] - 'A') * powers[i];
  }
  return sum;
}
int h1(int k) { return k % M; }
int h2(int k) { return 1 + (k % (M - 1)); }
int insert(char* str) {
  int key, h;
  key = getkey(str);
  for (int i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str) == 0) {
      return 0;
    } else if (strlen(H[h]) == 0) {
      strcpy(H[h], str);
      return 1;
    }
  }
  return 0;
}
int find(char* str) {
  int key, h;
  key = getkey(str);
  for (int i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str) == 0) {
      return 1;
    } else if (strlen(H[h]) == 0) {
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