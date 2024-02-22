#include <stdio.h>

int main() {
  int h, m, s, t;
  
  while (scanf("%d%d%d", &h, &m, &s) == 3) {
    t = (120 - h * 60 - m) * 60 - s;
    
    int hours = t / 3600;
    int minutes = (t / 60) % 60;
    int seconds = t % 60;
    
    printf("%02d:%02d:%02d\n", hours, minutes, seconds);
    printf("%02d:%02d:%02d\n", hours*2, minutes*2, seconds*2);
  }
  
  return 0;
}