#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<int> chk;
int n;
string ins, s;

int h(const string& s) {
  int ret = 0;
  for (char c : s) {
    ret *= 5;
    switch (c) {
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
    int hash_value = h(s);
    if (ins[0] == 'i') {
      chk.insert(hash_value);
    } else {
      cout << (chk.count(hash_value) ? "yes" : "no") << endl;
    }
  }
  return 0;
}