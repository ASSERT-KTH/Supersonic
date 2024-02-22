#include<stdio.h>

#define TWO_HOURS_IN_SECONDS 7200
#define SECONDS_IN_HOUR 3600
#define SECONDS_IN_MINUTE 60

main() {
  int h, m, s, t;
  while (1) {
    if (scanf("%d%d%d", &h, &m, &s) != 3) {
      break;
    }
    t = TWO_HOURS_IN_SECONDS - (h * SECONDS_IN_HOUR + m * SECONDS_IN_MINUTE + s);
    
    for (h = 0; h < 2; h++) {
      printf("%02d:%02d:%02d\n", t / SECONDS_IN_HOUR, 
                                (t / SECONDS_IN_MINUTE) % SECONDS_IN_MINUTE, 
                                t % SECONDS_IN_MINUTE);
    }
  }
}