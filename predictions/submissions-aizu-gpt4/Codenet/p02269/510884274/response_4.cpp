#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, bool> chk;
int n;
string ins, s;
int h(const string& s) {
  int ret = 0;
  for (char c : s) {
    ret = ret * 5 + (c == 'A' ? 1 : c == 'C' ? 2 : c == 'G' ? 3 : 4);
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
      cout << (chk[h(s)] ? "yes" : "no") << '\n';
    }
  }
  return 0;
}