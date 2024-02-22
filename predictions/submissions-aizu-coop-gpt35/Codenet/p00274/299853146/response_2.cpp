#include <stdio.h>

int main(void) {
  int n, k, i, flg;
  
  // Read the first number
  scanf("%d", &n);
  
  while (n != 0) {
    flg = 0;
    int sum = n;
    
    // Calculate the sum of input values
    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      if (k == 0) {
        sum = sum - 1;
      }
      if (k >= 2) {
        flg = 1;
      }
    }
    
    // Check if any input value is greater than or equal to 2
    if (flg == 1) {
      printf("%d\n", sum + 1);
    } else {
      printf("NA\n");
    }
    
    // Read the next number
    scanf("%d", &n);
  }
  
  return 0;
}