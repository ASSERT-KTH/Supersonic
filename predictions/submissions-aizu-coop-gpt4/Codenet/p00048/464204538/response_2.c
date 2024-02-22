#include <stdio.h>

int main() {
  float f;
  int i;

  while (scanf("%f", &f) != EOF) {
    i = f * 10;  // Convert float to int to improve performance.

    if (i > 910) {
      puts("heavy");
    } else if (i > 810) {
      puts("light heavy");
    } else if (i > 750) {
      puts("middle");
    } else if (i > 690) {
      puts("light middle");
    } else if (i > 640) {
      puts("welter");
    } else if (i > 600) {
      puts("light welter");
    } else if (i > 570) {
      puts("light");
    } else if (i > 540) {
      puts("feather");
    } else if (i > 510) {
      puts("bantam");
    } else if (i > 480) {
      puts("fly");
    } else {
      puts("light fly");
    }
  }

  return 0;
}