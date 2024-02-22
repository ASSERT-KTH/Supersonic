#include <cstdio>
#include <bitset>
using namespace std;

bitset<33554432> d;

int c(char str[12], int i = 0, int ans = 0) {
  if (str[i] == '\0') {
    return ans;
  }
  
  ans <<= 2;
  switch (str[i]) {
    case 'A':
      ans += 0;
      break;
    case 'C':
      ans += 1;
      break;
    case 'G':
      ans += 2;
      break;
    case 'T':
      ans += 3;
      break;
  }
  
  return c(str, i + 1, ans);
}

int main() {
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