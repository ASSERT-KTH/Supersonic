#include <stdio.h>

const char *names[] = {"heavy", "light heavy", "middle", "light middle", "welter", "light welter", "light", "feather", "bantam", "fly", "light fly"};
float limits[] = {91, 81, 75, 69, 64, 60, 57, 54, 51, 48, 0};
int size = sizeof(limits)/sizeof(limits[0]);

int main() {
  float f;
  while (scanf("%f", &f) == 1) {
    for (int i = 0; i < size; i++) {
      if (f > limits[i]) {
        printf("%s\n", names[i]);
        break;
      }
    }
  }
  return 0;
}