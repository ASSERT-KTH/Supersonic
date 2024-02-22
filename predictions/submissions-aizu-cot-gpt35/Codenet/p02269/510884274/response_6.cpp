#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

const int MAX_SIZE = 244140624;
bool chk[MAX_SIZE];

int calculateHash(const string& s) {
  int ret = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    ret *= 5;
    switch (s[i]) {
      case 'A':
        ret += 1;
        break;
      case 'C':
        ret += 2;
        break;
      case 'G':
        ret += 3;
        break;
      case 'T':
        ret += 4;
        break;
    }
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  while (n--) {
    string ins, s;
    cin >> ins >> s;
    if (ins[0] == 'i') {
      chk[calculateHash(s)] = true;
    } else {
      cout << (chk[calculateHash(s)] ? "yes" : "no") << '\n';
    }
  }
  return 0;
}