#include <stdio.h>

typedef struct {
  float threshold;
  const char* weightClass;
} WeightClass;

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
    {0, "light fly"}
};

int main() {
  float f;
  while (scanf("%f", &f) == 1) {
    const char* weightClass = "unknown";
    for (int i = 0; i < sizeof(weightClasses) / sizeof(weightClasses[0]); i++) {
      if (f > weightClasses[i].threshold) {
        weightClass = weightClasses[i].weightClass;
        break;
      }
    }
    puts(weightClass);
  }
  return 0;
}