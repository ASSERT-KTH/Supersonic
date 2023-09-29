#include <cstdio>

int main() {
  int n, k, s, flg;

  while (scanf("%d", &n), n) {
    s = n;
    flg = 0;
    while (n--) {
      scanf("%d", &k);
      s -= k == 0;
      flg |= k >= 2;
    }
    if (flg) {
      printf("%d\n", s + 1);
    } else {
      puts("NA");
    }
  }

  return 0;
}