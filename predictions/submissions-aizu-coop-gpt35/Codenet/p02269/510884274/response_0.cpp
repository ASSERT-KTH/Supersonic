#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<int> chk;
int n;
string ins, s;
int charToValue[128]; // Lookup table for character to value mapping

int h(const string& s) {
  int ret = 0;
  int power = 1;
  for (int i = s.size() - 1; i >= 0; --i) {
    ret += charToValue[s[i]] * power;
    power *= 5;
  }
  return ret;
}

int main() {
  // Populate the lookup table
  charToValue['A'] = 1;
  charToValue['C'] = 2;
  charToValue['G'] = 3;
  charToValue['T'] = 4;

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