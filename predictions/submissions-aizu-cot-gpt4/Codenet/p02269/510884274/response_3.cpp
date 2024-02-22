#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, bool> chk;
int n;
char ins;
string s;

int h(string s) {
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
    if (ins == 'i') {
      chk[h(s)] = true;
    } else {
      cout << (chk[h(s)] ? "yes" : "no") << endl;
    }
  }
  return 0;
}