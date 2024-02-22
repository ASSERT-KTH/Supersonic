#include <iostream>
#include <string.h>
#define M 1020001
#define L 14
using namespace std;
char H[M][L];

int getnum(char ch) {
  switch (ch) {
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
  int key = getkey(str);
  for (int i = 0;; i++) {
    int h = (h1(key) + i * h2(key)) % M;
    int cmp = strcmp(H[h], str);
    if (cmp) {
      if (H[h][0] == '\0') {
        strcpy(H[h], str);
        return 1;
      }
    } else {
      return 0;
    }
  }
}

int find(char str[]) {
  int key = getkey(str);
  for (int i = 0;; i++) {
    int h = (h1(key) + i * h2(key)) % M;
    int cmp = strcmp(H[h], str);
    if (cmp) {
      if (H[h][0] == '\0') {
        return 0;
      }
    } else {
      return 1;
    }
  }
}

int main() {
  int NumOfCom;
  cin >> NumOfCom;
  for (int i = 0; i < M; i++)
    H[i][L] = '\0';
  while (NumOfCom--) {
    char com[9], word[14];
    cin >> com >> word;
    if (com[0] == 'i') {
      insert(word);
    } else {
      cout << (find(word) ? "yes" : "no") << endl;
    }
  }
  return 0;
}