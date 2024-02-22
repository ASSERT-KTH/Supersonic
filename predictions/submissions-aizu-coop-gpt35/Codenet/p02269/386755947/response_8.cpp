#include <cstdio>
#include <bitset>
using namespace std;

bitset<33554432> d;
int k[128];

int c(char str[12]) {
  int ans = str[0], i = 1;
  for (i; str[i] != '\0'; i++) {
    ans <<= 2;
    ans |= k[str[i]];
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
    fgets(s, sizeof(s), stdin);
    fgets(str, sizeof(str), stdin);

    if (s[0] == 'i')
      d[c(str)] = true;
    else
      puts(d[c(str)] ? "yes" : "no");
  }
  return 0;
}