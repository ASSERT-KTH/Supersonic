#include <cstdio>
using namespace std;
constexpr int SZ = 1<<26;
bool d[SZ];
char k[128];
inline int c(char* str) {
  int ans = str[0], i = 1;
  while (str[i]) {
    ans = (ans << 2) + k[str[i++]];
  }
  return ans;
}
int main() {
  k['A'] = 0;
  k['C'] = 1;
  k['G'] = 2;
  k['T'] = 3;
  int n;
  scanf("%d", &n);
  char s[7], str[12];
  while (n--) {
    scanf("%s %s", s, str);
    if (s[0] == 'i')
      d[c(str)] = true;
    else
      puts(d[c(str)] ? "yes" : "no");
  }
  return 0;
}