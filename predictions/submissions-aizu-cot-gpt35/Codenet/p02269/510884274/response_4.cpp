#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> chk;
int n;
string ins, s;

int h(const string& s) {
  int ret = 0;
  for (char c : s) {
    ret <<= 2;
    if (c == 'C')
      ret |= 1;
    else if (c == 'G')
      ret |= 2;
    else if (c == 'T')
      ret |= 3;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
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