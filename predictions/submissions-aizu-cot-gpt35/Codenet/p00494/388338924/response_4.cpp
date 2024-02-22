#include <cstdio>
#include <cstring>

char x[1000005];

int main() {
  memset(x, 'A', sizeof(x));
  scanf("%s", x);
  size_t leng = strlen(x);
  int a = 0, b = 0, c = 0, d = 0, maxi = 0;

  for (a = 0; a < leng;) {
    if (x[a] != 'J') {
      a += 1;
    } else {
      while (x[a] == 'J') {
        b += 1;
        a += 1;
      }
      while (x[a] == 'O') {
        c += 1;
        a += 1;
      }
      while (x[a] == 'I') {
        d += 1;
        a += 1;
      }
      if (b >= c && c <= d) {
        maxi = (c > maxi) ? c : maxi;
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