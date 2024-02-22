#include <stdio.h>

#define MINUTE 60
#define HOUR 3600

int main() {
  int h, m, s, t;
  while (scanf("%d%d%d", &h, &m, &s) != EOF) {
    for (t = (120 - h * MINUTE - m) * MINUTE - s, h = 2; h--; t *= 3)
      printf("%02d:%02d:%02d\n", t / HOUR, t / MINUTE % MINUTE, t % MINUTE);
  }
  return 0;
}