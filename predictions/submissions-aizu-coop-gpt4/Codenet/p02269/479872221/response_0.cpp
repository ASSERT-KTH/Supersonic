#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define M 1020001
vector<string> H(M, "");

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

long long getkey(const string& word) {
  int sum = 0, p = 1;
  for (char ch : word) {
    sum += p * getnum(ch);
    p *= 5;
  }
  return sum;
}

int h1(int k) { return k % M; }
int h2(int k) { return 1 + (k % (M - 1)); }

bool insert(const string& str) {
  int key = getkey(str);
  int h1_val = h1(key);
  int h2_val = h2(key);
  for (int i = 0;; i++) {
    int h = (h1_val + i * h2_val) % M;
    if (H[h] != str) {
      if (H[h].empty()) {
        H[h] = str;
        return true;
      }
    } else {
      return false;
    }
  }
}

bool find(const string& str) {
  int key = getkey(str);
  int h1_val = h1(key);
  int h2_val = h2(key);
  for (int i = 0;; i++) {
    int h = (h1_val + i * h2_val) % M;
    if (H[h] != str) {
      if (H[h].empty()) {
        return false;
      }
    } else {
      return true;
    }
  }
}

int main() {
  string com, word;
  int NumOfCom;
  cin >> NumOfCom;
  while (NumOfCom--) {
    cin >> com >> word;
    if (com[0] == 'i') {
      insert(word);
    } else {
      cout << (find(word) ? "yes" : "no") << endl;
    }
  }
  return 0;
}