#include <stdio.h>

int main(void) {
  int h, m, s, t;
  while (scanf("%d%d%d", &h, &m, &s) == 3 && h != -1){
    t = (120 - h * 60 - m) * 60 - s;
    for (int i = 0; i < 2; ++i) {
      printf("%02d:%02d:%02d\n", t / 3600, t / 60 % 60, t % 60);
      t *= 3;
    }
  }
  return 0;
}