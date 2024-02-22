#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<int, bool> chk;
int n;
string ins, s;

int h(const string &s) {
  int ret = 0;
  for (char c : s) {
    ret = (ret << 2) + ret;
    if (c == 'A')
      ret += 1;
    else if (c == 'C')
      ret += 2;
    else if (c == 'G')
      ret += 3;
    else if (c == 'T')
      ret += 4;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); // For faster input
  cin >> n;
  while (n--) {
    cin >> ins >> s;
    int hval = h(s);
    if (ins[0] == 'i') {
      chk[hval] = true;
    } else {
      cout << (chk[hval] ? "yes" : "no") << endl;
    }
  }
  return 0;
}