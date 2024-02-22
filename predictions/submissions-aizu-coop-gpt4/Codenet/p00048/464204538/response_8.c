#include <stdio.h>

typedef struct {
  float weight_limit;
  const char* class_name;
} WeightClass;

int main() {
  WeightClass classes[] = {
    {91, "heavy"}, {81, "light heavy"}, {75, "middle"}, 
    {69, "light middle"}, {64, "welter"}, {60, "light welter"},
    {57, "light"}, {54, "feather"}, {51, "bantam"}, 
    {48, "fly"}, {0, "light fly"}
  };

  float weight;
  while (scanf("%f", &weight) == 1) {
    for (int i = 0; i < sizeof(classes) / sizeof(WeightClass); ++i) {
      if (weight > classes[i].weight_limit) {
        printf("%s\n", classes[i].class_name);
        break;
      }
    }
  }

  return 0;
}