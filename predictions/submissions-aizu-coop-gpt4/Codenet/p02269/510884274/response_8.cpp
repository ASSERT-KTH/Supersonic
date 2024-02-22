#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool chk[244140624];
int n;
string ins, s;
unordered_map<char, int> charMap = {{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};

int h(const string& s) {
  int ret = 0;
  int size = s.size();
  for (int i = 0; i < size; ++i) {
    ret = ((ret<<2) + ret) + charMap[s[i]]; // 5*ret = (ret<<2) + ret
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
      cout << (chk[h(s)] ? "yes" : "no") << endl;
    }
  }
  return 0;
}