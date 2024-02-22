#include <stdio.h>

#define NUM_CATEGORIES 11

const float thresholds[NUM_CATEGORIES] = {48, 51, 54, 57, 60, 64, 69, 75, 81, 91, FLT_MAX};
const char* categories[NUM_CATEGORIES] = {"light fly", "fly", "bantam", "feather", "light welter", "welter", "light middle", "middle", "light heavy", "heavy", "invalid"};

int main() {
  char input[100];
  float f;

  while (fgets(input, sizeof(input), stdin)) {
    if (sscanf(input, "%f", &f) == 1) {
      int i;
      for (i = 0; i < NUM_CATEGORIES; i++) {
        if (f <= thresholds[i]) {
          printf("%s\n", categories[i]);
          break;
        }
      }
      if (i == NUM_CATEGORIES) {
        printf("%s\n", categories[NUM_CATEGORIES - 1]);
      }
    }
    else {
      printf("Invalid input\n");
    }
  }

  return 0;
}