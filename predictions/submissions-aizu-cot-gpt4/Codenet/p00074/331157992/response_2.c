#include <stdio.h>

#define HOUR_IN_SECONDS 3600
#define MINUTE_IN_SECONDS 60
#define TARGET_HOUR 120

int main() {
  int hours, minutes, seconds, time_remaining;

  while(scanf("%d%d%d", &hours, &minutes, &seconds) == 3) {
    time_remaining = (TARGET_HOUR - hours * 60 - minutes) * MINUTE_IN_SECONDS - seconds;
    
    int hour_part = time_remaining / HOUR_IN_SECONDS;
    int minute_part = time_remaining / MINUTE_IN_SECONDS % 60;
    int second_part = time_remaining % 60;

    for (int i = 0; i < 2; ++i) {
      printf("%02d:%02d:%02d\n", hour_part, minute_part, second_part);
    }
  }

  return 0;
}