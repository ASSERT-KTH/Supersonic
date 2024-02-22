#include <stdio.h>

#define HEAVY_THRESHOLD 91.0
#define LIGHT_HEAVY_THRESHOLD 81.0
#define MIDDLE_THRESHOLD 75.0
#define LIGHT_MIDDLE_THRESHOLD 69.0
#define WELTER_THRESHOLD 64.0
#define LIGHT_WELTER_THRESHOLD 60.0
#define LIGHT_THRESHOLD 57.0
#define FEATHER_THRESHOLD 54.0
#define BANTAM_THRESHOLD 51.0
#define FLY_THRESHOLD 48.0

int main() {
  float weight;

  while (scanf("%f", &weight) != EOF) {
    if (weight > HEAVY_THRESHOLD) {
      printf("heavy\n");
    } else if (weight > LIGHT_HEAVY_THRESHOLD) {
      printf("light heavy\n");
    } else if (weight > MIDDLE_THRESHOLD) {
      printf("middle\n");
    } else if (weight > LIGHT_MIDDLE_THRESHOLD) {
      printf("light middle\n");
    } else if (weight > WELTER_THRESHOLD) {
      printf("welter\n");
    } else if (weight > LIGHT_WELTER_THRESHOLD) {
      printf("light welter\n");
    } else if (weight > LIGHT_THRESHOLD) {
      printf("light\n");
    } else if (weight > FEATHER_THRESHOLD) {
      printf("feather\n");
    } else if (weight > BANTAM_THRESHOLD) {
      printf("bantam\n");
    } else if (weight > FLY_THRESHOLD) {
      printf("fly\n");
    } else {
      printf("light fly\n");
    }
  }

  return 0;
}