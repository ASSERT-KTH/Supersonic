#include <iostream>
#include <bitset>
using namespace std;

constexpr int MAX_N = 244140624;

bitset<MAX_N> chk;
int n;
char ins[10];
char s[21];

int h(char* s) {
  int ret = 0;
  for (int i = 0; s[i] != '\0'; ++i) {
    ret *= 5;
    ret += s[i] - 'A' + 1;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  while (n--) {
    cin >> ins >> s;
    if (ins[0] == 'i') {
      chk.set(h(s), true);
    } else {
      cout << (chk.test(h(s)) ? "yes" : "no") << endl;
    }
  }
  return 0;
}