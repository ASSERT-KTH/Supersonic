#include <cstdio>
#include <cstring>
char x[1000005];
int a = 0, b = 0, c = 0, d = 0, maxi = 0;
int main() {
  fgets(x, 1000005, stdin);
  int leng = strlen(x);
  while (a < leng) {
    if (x[a] != 'J') {
      a++;
    } else {
      while (x[a] == 'J') {
        b++;
        a++;
      }
      while (x[a] == 'O') {
        c++;
        a++;
      }
      while (x[a] == 'I') {
        d++;
        a++;
      }
      if (b >= c && c <= d) {
        maxi = c > maxi ? c : maxi;
      }
      b = 0;
      c = 0;
      d = 0;
    }
  }
  printf("%d\n", maxi);
  return 0;
}