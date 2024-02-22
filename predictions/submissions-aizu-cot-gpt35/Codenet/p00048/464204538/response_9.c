#include <stdio.h>

int main() {
  float f;

  // Define the weight categories
  const char* categories[] = {"heavy",
                              "light heavy",
                              "middle",
                              "light middle",
                              "welter",
                              "light welter",
                              "light",
                              "feather",
                              "bantam",
                              "fly",
                              "light fly"};

  // Define the weight thresholds
  const float weights[] = {91, 81, 75, 69, 64, 60, 57, 54, 51, 48};

  while (scanf("%f", &f) != EOF) {
    int i;
    for (i = 0; i < sizeof(weights) / sizeof(weights[0]); i++) {
      if (f > weights[i]) {
        puts(categories[i]);
        break;
      }
    }
    if (i == sizeof(weights) / sizeof(weights[0])) {
      puts(categories[i]);
    }
  }

  return 0;
}