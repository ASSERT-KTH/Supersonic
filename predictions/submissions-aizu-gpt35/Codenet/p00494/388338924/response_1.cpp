#include <cstdio>
#include <cstring>
char x[1000005];
int a = 0, b = 0, c = 0, d = 0, leng, maxi = 0;
int main() {
  memset(x, 'A', sizeof(x));
  scanf("%s", x);
  leng = strlen(x);
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
  scanf("%d", &a);
  return 0;
}