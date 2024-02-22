#include <iostream>
#include <string>
#include <unordered_set>
#include <map>
using namespace std;
unordered_set<int> chk;
map<char, int> values = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
int n;
string ins, s;
int h(string s) {
  int ret = 0;
  for (int i = 0; i < s.size(); ++i) {
    ret *= 5;
    ret += values[s[i]];
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  while (n--) {
    cin >> ins >> s;
    int hash = h(s); // calculate the hash once
    if (ins[0] == 'i') {
      chk.insert(hash);
    } else {
      cout << (chk.count(hash) ? "yes" : "no") << endl;
    }
  }
  return 0;
}