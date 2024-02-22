#include <iostream>
#include <cstring>
using namespace std;

#define M 1020001
#define L 14

char H[M][L];

int charToNum(char ch) {
  switch(ch) {
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

long long getkey(char word[]) {
  int sum = 0;
  long long p = 1;
  for (int i = 0; word[i]; i++) {
    sum += p * charToNum(word[i]);
    p <<= 2;
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
  int h, i;
  for (i = 0; ; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (H[h][0] == '\0') {
      strcpy(H[h], str);
      return 1;
    }
    if (strcmp(H[h], str) == 0) {
      return 0;
    }
  }
}

int find(char str[]) {
  int key = getkey(str);
  int h, i;
  for (i = 0; ; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (H[h][0] == '\0') {
      return 0;
    }
    if (strcmp(H[h], str) == 0) {
      return 1;
    }
  }
}

int main() {
  char com[9], word[14];
  int NumOfCom;
  cin >> NumOfCom;
  memset(H, 0, sizeof(H));
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