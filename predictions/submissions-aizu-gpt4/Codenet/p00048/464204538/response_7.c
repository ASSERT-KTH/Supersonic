#include <stdio.h>

int main() {
  float f;
  const char *weights[] = {"light fly", "fly", "bantam", "feather", "light", "light welter", "welter", "light middle", "middle", "light heavy", "heavy"};
  float limits[] = {48, 51, 54, 57, 60, 64, 69, 75, 81, 91, 100};
  
  while(~scanf("%f", &f)){
      int i;
      for(i=0; i<11; i++){
          if(f <= limits[i]){
              puts(weights[i]);
              break;
          }
      }
  }
  return 0;
}