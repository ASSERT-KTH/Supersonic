#include <stdio.h>

int main() {
  double weight;
  while (scanf("%lf", &weight) == 1) {
    if (weight > 91)
      puts("heavy");
    else if (weight > 81)
      puts("light heavy");
    else if (weight > 75)
      puts("middle");
    else if (weight > 69)
      puts("light middle");
    else if (weight > 64)
      puts("welter");
    else if (weight > 60)
      puts("light welter");
    else if (weight > 57)
      puts("light");
    else if (weight > 54)
      puts("feather");
    else if (weight > 51)
      puts("bantam");
    else if (weight > 48)
      puts("fly");
    else
      puts("light fly");
  }
  return 0;
}