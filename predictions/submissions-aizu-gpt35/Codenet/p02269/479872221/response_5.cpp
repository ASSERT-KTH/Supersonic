#include <iostream>
#include <cstring>
#define M 1020001
#define L 14
char H[M][L];
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

unsigned long long getkey(char word[]) {
  unsigned long long sum = 0, p = 1;
  for (int i = 0; i < L; i++, p *= 5) {
    if (word[i] == '\0') break;
    sum += p * getnum(word[i]);
  }
  return sum;
}

int h1(unsigned long long k) { return k % M; }
int h2(unsigned long long k) { return 1 + (k % (M - 1)); }

bool insert(char str[]) {
  unsigned long long key = getkey(str);
  for (int i = 0; i < M; i++) {
    int h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str) == 0) {
      return false;
    } else if (strlen(H[h]) == 0) {
      strcpy(H[h], str);
      return true;
    }
  }
  return false;
}

bool find(char str[]) {
  unsigned long long key = getkey(str);
  for (int i = 0; i < M; i++) {
    int h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str) == 0) {
      return true;
    } else if (strlen(H[h]) == 0) {
      return false;
    }
  }
  return false;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int NumOfCom;
  std::cin >> NumOfCom;
  while (NumOfCom--) {
    char com[9], word[14];
    std::cin >> com >> word;
    if (com[0] == 'i') {
      insert(word);
    } else if (find(word)) {
      std::cout << "yes\n";
    } else {
      std::cout << "no\n";
    }
  }
  return 0;
}