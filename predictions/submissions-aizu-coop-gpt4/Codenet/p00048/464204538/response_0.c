#include <stdio.h>

int main() {
  float f;
  int ret;

  while ((ret = scanf("%f", &f)) != EOF) {
    // Check if input was a valid float
    if (ret != 1) {
        printf("Invalid input\n");
        continue;
    }

    // Use if-else statements instead of nested ternary operators
    if (f > 91)
        printf("heavy");
    else if (f > 81)
        printf("light heavy");
    else if (f > 75)
        printf("middle");
    else if (f > 69)
        printf("light middle");
    else if (f > 64)
        printf("welter");
    else if (f > 60)
        printf("light welter");
    else if (f > 57)
        printf("light");
    else if (f > 54)
        printf("feather");
    else if (f > 51)
        printf("bantam");
    else if (f > 48)
        printf("fly");
    else
        printf("light fly");
  }

  return 0;
}