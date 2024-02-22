#include <iostream>
#include <string>
#include <bitset>
using namespace std;

bitset<9765625> chk;
int n;
string ins, s;

int h(const string& s) {
  static const int CHAR_VALUES[256] = {
    /* 'A' */ 1,
    /* 'B' */ 0,
    /* 'C' */ 2,
    /* 'D' */ 0,
    /* 'E' */ 0,
    /* 'F' */ 0,
    /* 'G' */ 3,
    /* 'H' */ 0,
    /* 'I' */ 0,
    /* 'J' */ 0,
    /* 'K' */ 0,
    /* 'L' */ 0,
    /* 'M' */ 0,
    /* 'N' */ 0,
    /* 'O' */ 0,
    /* 'P' */ 0,
    /* 'Q' */ 0,
    /* 'R' */ 0,
    /* 'S' */ 0,
    /* 'T' */ 4,
    /* 'U' */ 0,
    /* 'V' */ 0,
    /* 'W' */ 0,
    /* 'X' */ 0,
    /* 'Y' */ 0,
    /* 'Z' */ 0,
    /* 'a' */ 0,
    /* 'b' */ 0,
    /* 'c' */ 0,
    /* 'd' */ 0,
    /* 'e' */ 0,
    /* 'f' */ 0,
    /* 'g' */ 0,
    /* 'h' */ 0,
    /* 'i' */ 0,
    /* 'j' */ 0,
    /* 'k' */ 0,
    /* 'l' */ 0,
    /* 'm' */ 0,
    /* 'n' */ 0,
    /* 'o' */ 0,
    /* 'p' */ 0,
    /* 'q' */ 0,
    /* 'r' */ 0,
    /* 's' */ 0,
    /* 't' */ 0,
    /* 'u' */ 0,
    /* 'v' */ 0,
    /* 'w' */ 0,
    /* 'x' */ 0,
    /* 'y' */ 0,
    /* 'z' */ 0,
  };

  int ret = 0;
  for (char c : s) {
    ret *= 5;
    ret += CHAR_VALUES[c];
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