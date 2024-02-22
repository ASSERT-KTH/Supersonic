#include <cstdio>
#include <string>
#include <unordered_set>
using namespace std;
unordered_set<int> chk;
int n;
char ins[10], s[14];
int h(char* s) {
  int ret = 0;
  for (int i = 0; s[i] != '\0'; ++i) {
    ret <<= 2;
    ret += ret;
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
  scanf("%d", &n);
  while (n--) {
    scanf("%s %s", ins, s);
    if (ins[0] == 'i') {
      chk.insert(h(s));
    } else {
      printf("%s\n", (chk.count(h(s)) ? "yes" : "no"));
    }
  }
  return 0;
}