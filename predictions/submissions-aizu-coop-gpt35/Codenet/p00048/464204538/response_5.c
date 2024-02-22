#include <stdio.h>

// Define a struct for weight class
typedef struct {
  float threshold;
  const char* name;
} WeightClass;

// Define an array of weight classes
const WeightClass weightClasses[] = {
    {91, "heavy"},
    {81, "light heavy"},
    {75, "middle"},
    {69, "light middle"},
    {64, "welter"},
    {60, "light welter"},
    {57, "light"},
    {54, "feather"},
    {51, "bantam"},
    {48, "fly"},
    {0, "light fly"} // Default weight class
};

int main() {
  float weight;
  int i;

  // Read weight from user input
  while (scanf("%f", &weight) == 1) {
    // Iterate over the weight classes array
    for (i = 0; i < sizeof(weightClasses) / sizeof(weightClasses[0]); i++) {
      // Check if weight is greater than the current threshold
      if (weight > weightClasses[i].threshold) {
        // Print the corresponding weight class name
        printf("%s\n", weightClasses[i].name);
        break;
      }
    }
    // If weight is smaller than all thresholds, it belongs to the default weight class
    if (i == sizeof(weightClasses) / sizeof(weightClasses[0])) {
      printf("%s\n", weightClasses[i].name);
    }
  }

  return 0;
}