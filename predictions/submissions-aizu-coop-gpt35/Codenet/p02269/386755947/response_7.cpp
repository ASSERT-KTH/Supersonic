#include <cstdio>
#include <bitset>
using namespace std;

std::bitset<33554432> d;
char k[128];

int c(char str[12]) {
  int ans = k[str[0]];
  for (int i = 1; str[i] != '\0'; i++) {
    ans <<= 2;
    ans += k[str[i]];
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

  while (n > 1) {
    scanf("%s %s", s, str);
    if (s[0] == 'i')
      d[c(str)] = true;
    else
      puts(d[c(str)] ? "yes" : "no");

    scanf("%s %s", s, str);
    if (s[0] == 'i')
      d[c(str)] = true;
    else
      puts(d[c(str)] ? "yes" : "no");

    n -= 2;
  }

  if (n == 1) {
    scanf("%s %s", s, str);
    if (s[0] == 'i')
      d[c(str)] = true;
    else
      puts(d[c(str)] ? "yes" : "no");
  }

  return 0;
}