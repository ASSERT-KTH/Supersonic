#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int n;
string ins, s;

int h(const string& s) {
  int ret = 0;
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

  unordered_set<int> s;

  while (n--) {
    cin >> ins >> s;

    if (ins[0] == 'i') {
      s.insert(h(s));
    } else {
      cout << (s.find(h(s)) != s.end() ? "yes" : "no") << endl;
    }
  }

  return 0;
}