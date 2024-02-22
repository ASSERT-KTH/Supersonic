#include <stdio.h>

int main() {
  for (int h, m, s; scanf("%d%d%d", &h, &m, &s) && h+1;) {
    int t = (120 - (h * 60 + m)) * 60 - s;
    t *= 3;
    printf("%02d:%02d:%02d\n", t / 3600, t / 60 % 60, t % 60);
  }
  return 0;
}