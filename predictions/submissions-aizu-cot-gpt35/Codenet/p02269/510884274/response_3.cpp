#include <iostream>
#include <vector>
using namespace std;

vector<bool> chk(244140624, false);
int n;
string ins, s;

int h(string s) {
  static int lookup[128];  // Lookup table for characters
  lookup['A'] = 1;
  lookup['C'] = 2;
  lookup['G'] = 3;
  lookup['T'] = 4;

  int ret = 0;
  for (int i = 0; i < s.size(); ++i) {
    ret *= 5;
    ret += lookup[s[i]];
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
      cout << (chk[h(s)] ? "yes" : "no") << "\n";
    }
  }
  return 0;
}