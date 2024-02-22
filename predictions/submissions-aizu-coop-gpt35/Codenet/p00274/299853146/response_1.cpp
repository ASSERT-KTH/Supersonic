#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_N 1000000

int main(void) {
  uint32_t bitset[MAX_N / 32 + 1] = {0}; // Bitset to store presence of non-zero integers
  int n, k;

  while (scanf("%d", &n) == 1 && n != 0) {
    // Clear the bitset for each iteration
    for (int i = 0; i <= n / 32; i++) {
      bitset[i] = 0;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &k);
      if (k >= 2) {
        count++;
      } else if (k == 1) {
        // Set the bit in the bitset corresponding to the index of the non-zero integer
        bitset[i / 32] |= (1 << (i % 32));
      }
    }

    if (count > 0) {
      printf("%d\n", count + 1);
    } else {
      printf("NA\n");
    }
  }

  return 0;
}