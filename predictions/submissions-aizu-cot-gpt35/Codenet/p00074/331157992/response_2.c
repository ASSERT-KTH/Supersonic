#include <stdio.h>

int main() {
  int h, m, s;
  while (scanf("%d%d%d", &h, &m, &s) * -~h) {
    int remainingTime = (120 - h * 60 - m) * 60 - s;
    int hours = remainingTime / 3600;
    int minutes = (remainingTime / 60) % 60;
    int seconds = remainingTime % 60;

    for (int i = 0; i < 2; i++) {
      printf("%02d:%02d:%02d\n", hours, minutes, seconds);
      remainingTime *= 3;
      hours = remainingTime / 3600;
      minutes = (remainingTime / 60) % 60;
      seconds = remainingTime % 60;
    }
  }

  return 0;
}