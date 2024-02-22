#include <cstdio>
#include <string>
#include <vector>
using namespace std;

vector<bool> chk(244140624);

int h(const string& s) {
  int ret = 0;
  for (char c : s) {
    ret <<= 3;
    ret |= c & 7;
  }
  return ret;
}

int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    char ins[2], s[21];
    scanf("%1s %s", ins, s);
    if (ins[0] == 'i') {
      chk[h(s)] = true;
    } else {
      printf("%s\n", chk[h(s)] ? "yes" : "no");
    }
  }
  return 0;
}