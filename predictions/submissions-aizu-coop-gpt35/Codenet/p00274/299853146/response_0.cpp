#include <stdio.h>

#define MAX_NUMBERS 100

int main(void) {
  int numbers[MAX_NUMBERS]; // Array to store the numbers
  int n, k, i, flg;

  while (1) {
    flg = 0;
    scanf("%d", &n);

    if (n == 0)
      break;

    for (i = 0; i < n; i++) {
      scanf("%d", &k);
      numbers[i] = k; // Store the number in the array

      if (k == 0) {
        n--; // Decrement the count if the number is zero
      }

      if (k >= 2) {
        flg = 1;
      }
    }

    if (flg == 1) {
      printf("%d\n", n);
    } else {
      printf("NA\n");
    }
  }

  return 0;
}