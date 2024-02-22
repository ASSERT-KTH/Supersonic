#include <stdio.h>

int main() {
  int h, m, s, t;
  while(scanf("%d%d%d", &h, &m, &s) != EOF) {
    if(h < 0) {
      break;
    }
    t = (120 - h * 60 - m) * 60 - s;
    printf("%02d:%02d:%02d\n", t / 3600, t / 60 % 60, t % 60);
    printf("%02d:%02d:%02d\n", t / 3600, t / 60 % 60, t % 60);
  }
  return 0;
}