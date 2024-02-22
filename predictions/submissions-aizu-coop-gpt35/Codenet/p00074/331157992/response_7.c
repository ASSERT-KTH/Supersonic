#include <stdio.h>

int main() {
  int h, m, s, t;

  while (scanf("%d%d%d", &h, &m, &s) == 3 && (h > 0 || m > 0 || s > 0)) {
    t = (120 * 60) - (h * 3600 + m * 60 + s);

    for (int i = 0; i < 2; i++) {
      int hours = t / 3600;
      int minutes = (t / 60) % 60;
      int seconds = t % 60;

      printf("%02d:%02d:%02d\n", hours, minutes, seconds);

      t *= 3;
    }
  }

  return 0;
}