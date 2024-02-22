#include <iostream>
#include <string>
using namespace std;
bool chk[244140624];
int n;
string ins, s;
int h(const string& s) {
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
  ios::sync_with_stdio(false);
  cin >> n;
  while (n--) {
    cin >> ins >> s;
    int hash = h(s);
    if (ins[0] == 'i') {
      chk[hash] = true;
    } else {
      cout << (chk[hash] ? "yes" : "no") << '\n';
    }
  }
  return 0;
}