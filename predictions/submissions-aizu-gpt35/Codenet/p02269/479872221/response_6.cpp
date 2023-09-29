#include <iostream>
#include <cstring>
#define M 1020001
#define L 14

char H[M][L];
const int base = 5;

long long getkey(const char *word) {
  long long sum = 0;
  for (int i = 0; word[i] != '\0'; i++) {
    sum = sum * base + (word[i] - 'A' + 1);
  }
  return sum;
}

int h1(long long k) { return k % M; }
int h2(long long k) { return 1 + (k % (M - 1)); }

int insert(const char *str) {
  long long key = getkey(str);
  for (int i = 0;; i++) {
    int h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str) == 0) {
      return 0;
    } else if (H[h][0] == '\0') {
      strcpy(H[h], str);
      return 1;
    }
  }
  return 0;
}

int find(const char *str) {
  long long key = getkey(str);
  for (int i = 0;; i++) {
    int h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str) == 0) {
      return 1;
    } else if (H[h][0] == '\0') {
      return 0;
    }
  }
  return 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int NumOfCom;
  std::cin >> NumOfCom;
  while (NumOfCom--) {
    char com[9], word[14];
    std::cin >> com >> word;
    if (com[0] == 'i') {
      insert(word);
    } else {
      std::cout << (find(word) ? "yes" : "no") << '\n';
    }
  }
  return 0;
}