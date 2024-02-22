#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

const int MAX_N = 1000000;
const int BASE = 5;
const int MOD = 244140625;

unordered_set<int> chk;
int n;
string ins, s;
int charToValue[128];

void initCharToValue() {
  charToValue['A'] = 1;
  charToValue['C'] = 2;
  charToValue['G'] = 3;
  charToValue['T'] = 4;
}

int h(const string& s) {
  int ret = 0;
  for (char c : s) {
    ret = (ret * BASE + charToValue[c]) % MOD;
  }
  return ret;
}

int main() {
  initCharToValue();
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