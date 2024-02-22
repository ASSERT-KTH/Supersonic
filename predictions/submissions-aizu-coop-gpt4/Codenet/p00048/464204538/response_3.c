#include <stdio.h>

typedef struct {
  float weight;
  const char* category;
} WeightCategory;

WeightCategory categories[] = {
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
    int i;
    for (i = 0; f <= categories[i].weight; i++);
    puts(categories[i].category);
  }
  return 0;
}