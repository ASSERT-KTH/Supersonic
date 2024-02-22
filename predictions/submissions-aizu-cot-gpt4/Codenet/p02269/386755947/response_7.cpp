#include <cstdio>
using namespace std;

int c(char str[12], int k[128]) {
  int ans = str[0], i = 1;
  for (; str[i] != '\0'; i++) {
    ans += k[str[i]];
    ans <<= 2;
  }
  return ans;
}

int main() {
  bool d[33554432];
  char k[128];
  k['A'] = 0;
  k['C'] = 1;
  k['G'] = 2;
  k['T'] = 3;
  int n;
  scanf("%d", &n);
  char ch, str[12];
  while (n--) {
    scanf(" %c %s", &ch, str);
    if (ch == 'i')
      d[c(str,k)] = true;
    else
      printf(d[c(str,k)] ? "yes\n" : "no\n");
  }
  return 0;
}