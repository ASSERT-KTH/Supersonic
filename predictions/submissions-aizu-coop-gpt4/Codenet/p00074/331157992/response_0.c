#include <stdio.h>

int main() {
  int hours, minutes, seconds, remaining_time;
  int hours_remaining, minutes_remaining, seconds_remaining;

  while (scanf("%d %d %d", &hours, &minutes, &seconds) == 3) {
    // Compute remaining time in seconds
    remaining_time = (120 - hours * 60 - minutes) * 60 - seconds;

    // Compute remaining hours, minutes and seconds
    hours_remaining = remaining_time / 3600;
    minutes_remaining = (remaining_time / 60) % 60;
    seconds_remaining = remaining_time % 60;

    // Print remaining time
    printf("%02d:%02d:%02d\n", hours_remaining, minutes_remaining, seconds_remaining);

    // Triple remaining time
    remaining_time *= 3;

    // Compute remaining hours, minutes and seconds
    hours_remaining = remaining_time / 3600;
    minutes_remaining = (remaining_time / 60) % 60;
    seconds_remaining = remaining_time % 60;

    // Print remaining time tripled
    printf("%02d:%02d:%02d\n", hours_remaining, minutes_remaining, seconds_remaining);
  }

  return 0;
}