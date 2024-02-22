#include <stdio.h>

int main() {
  int f;
  char* weightCategories[] = {
    "light fly",
    "fly",
    "bantam",
    "feather",
    "light",
    "light welter",
    "welter",
    "light middle",
    "middle",
    "light heavy",
    "heavy"
  };

  while (scanf("%d", &f) > 0) {
    int index = (f - 48) / 3;
    if (index >= 0 && index < 11) {
      printf("%s\n", weightCategories[index]);
    }
  }

  return 0;
}