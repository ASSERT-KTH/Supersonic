#include <iostream>
#include <string>
using namespace std;

bool chk[1048577];
int n;
string ins, s;

int h(const string& s) {
  static int lookup[256] = {
    0, 1, 0, 2, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, // A, C, G, T
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // other characters
    // repeat the pattern for the remaining characters
  };

  int ret = 0;
  for (char c : s) {
    ret <<= 2; // multiply by 4 (shift left by 2 bits)
    ret |= lookup[c]; // bitwise OR with the converted number
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