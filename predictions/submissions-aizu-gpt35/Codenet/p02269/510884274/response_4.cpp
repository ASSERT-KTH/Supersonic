#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
unordered_set<long long> chk;
int n;
string ins, s;
long long h(string s) {
  long long ret = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    ret *= 5;
    if (s[i] == 'A')
      ret += 1;
    else if (s[i] == 'C')
      ret += 2;
    else if (s[i] == 'G')
      ret += 3;
    else if (s[i] == 'T')
      ret += 4;
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  while (n--) {
    cin >> ins >> s;
    if (ins[0] == 'i') {
      chk.insert(h(s));
    } else {
      cout << (chk.count(h(s)) ? "yes" : "no") << endl;
    }
  }
  return 0;
}