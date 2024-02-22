#include <cstdio>
#include <cstring>

char x[1000005];

int main() {
  scanf("%s", x);
  int leng = strlen(x);

  int a = 0, b, c, d, maxi = 0;
  while (a < leng) {
    if (x[a] == 'J') {
      b = 1;
      while (x[a + b] == 'J') {
        b++;
      }
      c = 0;
      while (x[a + b + c] == 'O') {
        c++;
      }
      d = 0;
      while (x[a + b + c + d] == 'I') {
        d++;
      }
      if (b >= c && c <= d) {
        maxi = (c > maxi) ? c : maxi;
      }
      a += b + c + d;
    } else {
      a++;
    }
  }
  printf("%d\n", maxi);
  scanf("%*d");
  return 0;
}