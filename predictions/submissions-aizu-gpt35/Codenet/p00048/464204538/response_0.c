#include <stdio.h>

int main() {
  float f;
  while(scanf("%f", &f) == 1) {
    if(f > 91)
      printf("heavy\n");
    else if(f > 81)
      printf("light heavy\n");
    else if(f > 75)
      printf("middle\n");
    else if(f > 69)
      printf("light middle\n");
    else if(f > 64)
      printf("welter\n");
    else if(f > 60)
      printf("light welter\n");
    else if(f > 57)
      printf("light\n");
    else if(f > 54)
      printf("feather\n");
    else if(f > 51)
      printf("bantam\n");
    else if(f > 48)
      printf("fly\n");
    else
      printf("light fly\n");
  }
  return 0;
}