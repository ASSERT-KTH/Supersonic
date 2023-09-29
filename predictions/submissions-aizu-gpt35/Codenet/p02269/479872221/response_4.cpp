#include <iostream>
#include <cstring>
#include <string>
#define M 1020001
#define L 14

char H[M][L+1];

int getnum(char ch) {
  switch(ch) {
    case 'A': return 1;
    case 'C': return 2;
    case 'G': return 3;
    default: return 4;
  }
}

long long getkey(const char* word) {
  int sum = 0, p = 1;
  for (const char* c = word; *c; ++c) {
    sum += p * getnum(*c);
    p *= 5;
  }
  return sum;
}

int h1(long long k) { return k % M; }
int h2(long long k) { return 1 + (k % (M - 1)); }

int insert(const char* str) {
  long long key = getkey(str);
  for (int i = 0;; ++i) {
    const int h = (h1(key) + i * h2(key)) % M;
    if (std::strcmp(H[h], str) == 0) return 0;
    if (std::strlen(H[h]) == 0) {
      std::strcpy(H[h], str);
      return 1;
    }
  }
  return 0;
}

bool find(const char* str) {
  long long key = getkey(str);
  for (int i = 0;; ++i) {
    const int h = (h1(key) + i * h2(key)) % M;
    if (std::strcmp(H[h], str) == 0) return true;
    if (std::strlen(H[h]) == 0) return false;
  }
  return false;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int NumOfCom;
  std::cin >> NumOfCom;

  std::memset(H, 0, sizeof(H));

  while (NumOfCom--) {
    char com[9], word[L+1];
    std::cin >> com >> word;
    if (com[0] == 'i') {
      insert(word);
    } else {
      std::cout << (find(word) ? "yes" : "no") << '\n';
    }
  }

  return 0;
}