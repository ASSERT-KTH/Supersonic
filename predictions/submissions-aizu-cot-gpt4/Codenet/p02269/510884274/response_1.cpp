#include <iostream>
#include <string_view>
using namespace std;
bool chk[244140624];
int n;
string_view ins, s;
int h(string_view s) {
  int ret = 0;
  int size = s.size();
  for (int i = 0; i < size; ++i) {
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
    if (ins[0] == 'i') {
      chk[h(s)] = true;
    } else {
      cout << (chk[h(s)] ? "yes" : "no") << '\n';
    }
  }
  return 0;
}