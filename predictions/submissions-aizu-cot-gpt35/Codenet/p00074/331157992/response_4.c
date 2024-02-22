#include <stdio.h>

int main() {
  int h, m, s;
  
  while (scanf("%d%d%d", &h, &m, &s) && h != 0) {
    int t = (120 - h * 60 - m) * 60 - s;
    
    printf("%02d:%02d:%02d\n", t / 3600, (t / 60) % 60, t % 60);
    printf("%02d:%02d:%02d\n", 3 * (t / 3600), (3 * (t / 60) % 60), (3 * t) % 60);
  }
  
  return 0;
}