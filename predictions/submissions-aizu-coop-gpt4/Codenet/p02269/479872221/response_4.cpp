#include <iostream>
#include <string>
#define M 1020001
#define L 14

using namespace std;

long long H[M] = {0};
int charToKey[128] = {0};

int getnum(char ch) {
  return charToKey[ch];
}

long long getkey(char word[]) {
  long long sum = 0, p = 1;
  for (int i = 0; word[i]; i++) {
    sum += p * getnum(word[i]);
    p *= 5;
  }
  return sum;
}

int h1(int k) { return k % M; }

int h2(int k) { return 1 + (k % (M - 1)); }

int insert(char str[]) {
  long long key = getkey(str), h, h1val = h1(key), h2val = h2(key);
  for (int i = 0;; i++) {
    h = (h1val + i * h2val) % M;
    if (H[h] == 0) {
      H[h] = key;
      return 1;
    } else if (H[h] == key) {
      return 0;
    }
  }
}

int find(char str[]) {
  long long key = getkey(str), h, h1val = h1(key), h2val = h2(key);
  for (int i = 0;; i++) {
    h = (h1val + i * h2val) % M;
    if (H[h] == key) {
      return 1;
    } else if (H[h] == 0) {
      return 0;
    }
  }
}

int main() {
  string com, word;
  int NumOfCom;
  cin >> NumOfCom;

  // Precompute character to key mapping
  charToKey['A'] = 1; charToKey['C'] = 2; charToKey['G'] = 3; charToKey['T'] = 4;

  while (NumOfCom--) {
    cin >> com >> word;
    if (com[0] == 'i') {
      insert(&word[0]);
    } else {
      if (find(&word[0])) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    }
  };
  return 0;
}