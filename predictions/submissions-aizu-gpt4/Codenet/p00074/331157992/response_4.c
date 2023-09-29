#include <stdio.h>

int main() {
  int h, m, s, t;
  while (scanf("%d%d%d", &h, &m, &s) == 3) {
    t = (7200 - h * 3600 - m * 60 - s);
    printf("%02d:%02d:%02d\n", t / 3600, t / 60 % 60, t % 60);

    t *= 3;
    printf("%02d:%02d:%02d\n", t / 3600, t / 60 % 60, t % 60);
  }

  return 0;
}