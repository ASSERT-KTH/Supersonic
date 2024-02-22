#include <stdio.h>

int main() {
  float f;
  char* weight_classes[] = {"heavy", "light heavy", "middle", "light middle", "welter", "light welter", "light", "feather", "bantam", "fly", "light fly"};
  float weight_thresholds[] = {91, 81, 75, 69, 64, 60, 57, 54, 51, 48};
  int num_classes = sizeof(weight_thresholds) / sizeof(float);
    
  while (scanf("%f", &f) != EOF){
    char* result;
    for (int i=0; i < num_classes; i++){
      if (f > weight_thresholds[i]){
        result = weight_classes[i];
        break;
      }
    }
    if (!result){
      result = weight_classes[num_classes];
    }
    puts(result);
  }

  return 0;
}