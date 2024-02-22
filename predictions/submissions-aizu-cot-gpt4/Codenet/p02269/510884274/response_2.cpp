#include <iostream>
#include <string>
#include <bitset>
using namespace std;

bitset<1048576> chk;
int n;
string ins, s;

int h(string s) {
  int ret = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    ret *= 5;
    switch (s[i]) {
      case 'A': ret += 1; break;
      case 'C': ret += 2; break;
      case 'G': ret += 3; break;
      case 'T': ret += 4; break;
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  while (n--) {
    cin >> ins >> s;
    if (ins[0] == 'i') {
      chk[h(s)] = true;
    } else {
      cout << (chk[h(s)] ? "yes" : "no") << endl;
    }
  }
  return 0;
}