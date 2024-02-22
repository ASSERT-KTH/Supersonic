#include <stdio.h>

int main(void) {
  double f;
  while (scanf("%lf", &f) == 1) {
    const char* weightClass = (f > 91) ? "heavy\n"
                             : (f > 81) ? "light heavy\n"
                             : (f > 75) ? "middle\n"
                             : (f > 69) ? "light middle\n"
                             : (f > 64) ? "welter\n"
                             : (f > 60) ? "light welter\n"
                             : (f > 57) ? "light\n"
                             : (f > 54) ? "feather\n"
                             : (f > 51) ? "bantam\n"
                             : (f > 48) ? "fly\n"
                             : "light fly\n";
    puts(weightClass);
  }
  return 0;
}