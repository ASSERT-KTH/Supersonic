#include <iostream>
#include <string>
#include <bitset>
using namespace std;

const int MAX_SIZE = 244140624;
bitset<MAX_SIZE> chk;

int h(const string& s) {
  static const int lookup[] = {0, 1, 2, 3, 4};
  int ret = 0;
  for (char c : s) {
    ret *= 5;
    ret += lookup[c - 'A'];
  }
  return ret;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    string ins, s;
    cin >> ins >> s;
    if (ins[0] == 'i') {
      chk.set(h(s));
    } else {
      cout << (chk.test(h(s)) ? "yes" : "no") << '\n';
    }
  }
  return 0;
}