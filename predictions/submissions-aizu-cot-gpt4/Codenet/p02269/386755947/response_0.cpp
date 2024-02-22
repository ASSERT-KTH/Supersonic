#include <cstdio>
using namespace std;
bool d[33554432];
char k[128];

inline int c(char str[12]) {
  return (k[str[0]] << 18) + (k[str[1]] << 16) + (k[str[2]] << 14) + (k[str[3]] << 12) + (k[str[4]] << 10) 
    + (k[str[5]] << 8) + (k[str[6]] << 6) + (k[str[7]] << 4) + (k[str[8]] << 2) + k[str[9]];
}

int main() {
  k['A'] = 0;
  k['C'] = 1;
  k['G'] = 2;
  k['T'] = 3;
  int n;
  scanf("%d\n", &n);
  char s[7], str[12];
  while (n--) {
    fgets(s, 3, stdin);
    fgets(str, 12, stdin);
    if (s[0] == 'i')
      d[c(str)] = true;
    else
      printf("%s\n", d[c(str)] ? "yes" : "no");
  }
  return 0;
}