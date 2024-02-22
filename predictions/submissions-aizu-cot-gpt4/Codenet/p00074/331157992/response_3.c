#include <stdio.h>

int main() {
  int h = 0, m = 0, s = 0, t = 0;
  while (scanf("%d%d%d", &h, &m, &s) != EOF) {
    int temp = 120 - h * 60 - m;
    t = temp * 60 - s;
    for (h = 2; h--; t *= 3) {
      printf("%02d:%02d:%02d\n", t / 3600, t / 60 % 60, t % 60);
    }
  }
  return 0;
}