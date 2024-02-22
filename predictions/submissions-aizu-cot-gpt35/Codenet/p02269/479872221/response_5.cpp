#include <iostream>
using namespace std;

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

long long getkey(char word[]) {
  long long sum = 0;
  int p = 1;
  for (int i = 0; word[i]; i++) {
    sum = sum + p * getnum(word[i]);
    p = p << 2;  // Equivalent to multiplying by 5
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
  int key, h, i;
  key = getkey(str);
  for (i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str)) {
      if (H[h][0] == '\0') {
        strcpy(H[h], str);
        return 1;
      }
    } else {
      return 0;
    }
  }
  return 0;
}

int find(char str[]) {
  int key, h, i;
  key = getkey(str);
  for (i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str)) {
      if (H[h][0] == '\0') {
        return 0;
      }
      continue;
    } else {
      return 1;
    }
  }
  return 0;
}

int main() {
  char com[9], word[14];
  int NumOfCom;
  cin >> NumOfCom;
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
  };
  return 0;
}