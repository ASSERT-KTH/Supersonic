#include <cstdio>
using namespace std;
bool d[33554432];
char k[128];
int c(char *str) {
  int ans = *str++;
  while (*str != '\0') {
    ans <<= 2;
    ans += k[*str++];
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
    char cmd = getchar();
    scanf("%s", str);
    if (cmd == 'i')
      d[c(str)] = true;
    else
      printf(d[c(str)] ? "yes\n" : "no\n");
  }
  return 0;
}