#include<stdio.h>

#define HOURS_IN_DAY 24
#define MINUTES_IN_HOUR 60
#define SECONDS_IN_MINUTE 60
#define TWICE 2
#define TRIPLE 3

int main() {
  int hours, minutes, seconds, timeInSeconds, originalTime;
  while(scanf("%d%d%d", &hours, &minutes, &seconds) == 3 && hours != -1){
    timeInSeconds = (HOURS_IN_DAY * MINUTES_IN_HOUR - hours * MINUTES_IN_HOUR - minutes) * SECONDS_IN_MINUTE - seconds;
    originalTime = timeInSeconds;
    for (int i = TWICE; i--; timeInSeconds = originalTime * TRIPLE)
      printf("%02d:%02d:%02d\n", timeInSeconds / (MINUTES_IN_HOUR * SECONDS_IN_MINUTE), timeInSeconds / SECONDS_IN_MINUTE % MINUTES_IN_HOUR, timeInSeconds % SECONDS_IN_MINUTE);
  }
  return 0;
}