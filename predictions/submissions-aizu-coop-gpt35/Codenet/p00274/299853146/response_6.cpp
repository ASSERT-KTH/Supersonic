#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char buffer[1024];
  int count, num;
  
  while (1) {
    // Read the input line
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
      break;
    }
    
    // Parse the count of numbers in the sequence
    count = strtol(buffer, NULL, 10);
    if (count == 0) {
      break;
    }
    
    int nonzero_count = 0;
    int has_greater_than_2 = 0;
    
    // Parse each number and perform calculations
    for (int i = 0; i < count; i++) {
      // Parse the number
      num = strtol(buffer, NULL, 10);
      
      if (num == 0) {
        nonzero_count++;
      }
      if (num >= 2) {
        has_greater_than_2 = 1;
        break;
      }
    }
    
    if (has_greater_than_2) {
      printf("%d\n", nonzero_count + 1);
    } else {
      printf("NA\n");
    }
  }
  
  return 0;
}