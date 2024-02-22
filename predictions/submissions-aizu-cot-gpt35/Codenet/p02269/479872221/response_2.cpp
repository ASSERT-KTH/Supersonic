#include <iostream>
using namespace std;

#define M 1020001
#define L 14

char H[M][L];

int num[256];
int p[L];

void init() {
  num['A'] = 1;
  num['C'] = 2;
  num['G'] = 3;
  num['T'] = 4;

  p[0] = 1;
  for (int i = 1; i < L; i++) {
    p[i] = p[i-1] * 5;
  }
}

long long getkey(char word[]) {
  int sum = 0;
  for (int i = 0; word[i]; i++) {
    sum = sum + p[i] * num[word[i]];
  }
  return sum;
}

int h1(int k) {
  return k % M;
}

int h2(int k) {
  return 1 + (k % (M - 1));
}

int insert(char str[]) {
  int key = getkey(str);
  for (int i = 0;; i++) {
    int h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str) == 0) {
      return 0;
    }
    if (strlen(H[h]) == 0) {
      strcpy(H[h], str);
      return 1;
    }
  }
  return 0;
}

int find(char str[]) {
  int key = getkey(str);
  for (int i = 0;; i++) {
    int h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str) == 0) {
      return 1;
    }
    if (strlen(H[h]) == 0) {
      return 0;
    }
  }
  return 0;
}

int main() {
  init();

  char com[9], word[L];
  int NumOfCom;
  cin >> NumOfCom;

  for (int i = 0; i < M; i++) {
    H[i][L-1] = '\0';
  }

  while (NumOfCom) {
    cin >> com >> word;
    if (com[0] == 'i') {
      insert(word);
    } else {
      if (find(word)) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
    NumOfCom--;
  }

  return 0;
}