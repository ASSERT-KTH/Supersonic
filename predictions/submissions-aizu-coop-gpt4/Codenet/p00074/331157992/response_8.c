#include <stdio.h>

int main() {
  int h, m, s, t;
  while (scanf("%d%d%d", &h, &m, &s) != EOF) {
    // Calculate the time difference.
    t = (120 - h * 60 - m) * 60 - s;

    // Print the time difference twice.
    for (h = 0; h < 2; h++) {
      printf("%02d:%02d:%02d\n", t / 3600, t / 60 % 60, t % 60);
      // Triple the time difference after the first print.
      t *= 3;
    }
  }
  return 0;
}