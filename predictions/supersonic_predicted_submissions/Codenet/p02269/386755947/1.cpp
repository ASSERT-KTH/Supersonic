#include <cstdio>
using namespace std;
char k[128];
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
