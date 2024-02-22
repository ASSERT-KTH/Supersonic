#include <iostream>
#include <string>
#include <bitset>
using namespace std;

const int MAX = 244140624;
bitset<MAX> chk;
int n;
string ins, s;

int h(string s) {
  int ret = 0;
  for (int i = 0; i < s.size(); ++i) {
    ret *= 5;
    switch(s[i]) {
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
  ios::sync_with_stdio(false);
  cin >> n;
  while (n--) {
    cin >> ins >> s;
    if (ins == "insert") {
      chk.set(h(s));
    } else {
      cout << (chk.test(h(s)) ? "yes" : "no") << endl;
    }
  }
  return 0;
}