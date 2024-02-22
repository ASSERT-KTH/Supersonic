#include <cstdio>
#include <vector>
using namespace std;

int c(char str[12], char k[128]) {
  int ans = str[0], i = 1;
  for (i; str[i] != '\0'; i++) {
    ans <<= 2;
    ans += k[str[i]];
  }
  return ans;
}

int main() {
  char k[128];
  k['C'] = 1;
  k['G'] = 2;
  k['T'] = 3;
  vector<bool> d(33554432);
  int n;
  scanf("%d", &n);
  char s[7], str[12];
  while (n--) {
    scanf("%s %s", s, str);
    if (s[0] == 'i')
      d[c(str, k)] = true;
    else
      puts(d[c(str, k)] ? "yes" : "no");
  }
  return 0;
}