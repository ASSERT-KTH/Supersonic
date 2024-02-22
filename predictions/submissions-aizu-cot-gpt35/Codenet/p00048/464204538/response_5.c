#include <stdio.h>

int main() {
  for (;;) {
    float f;
    if (~scanf("%f", &f)) {
      if (f > 91)
        puts("heavy");
      else if (f > 81)
        puts("light heavy");
      else if (f > 75)
        puts("middle");
      else if (f > 69)
        puts("light middle");
      else if (f > 64)
        puts("welter");
      else if (f > 60)
        puts("light welter");
      else if (f > 57)
        puts("light");
      else if (f > 54)
        puts("feather");
      else if (f > 51)
        puts("bantam");
      else if (f > 48)
        puts("fly");
      else
        puts("light fly");
    } else {
      break;
    }
  }
  return 0;
}