#include <stdio.h>
#include <string.h>

int R[99];
int bit_position, flip_count, total_bit_count;

int main() {
  int c, count = 0;
  while ((c = getchar()) != EOF) {
    total_bit_count += !!R[c];
    flip_count += !(R[c] ^= 1 << bit_position % 5);
    if (++count > 9) {
      printf("%d %d\n", flip_count, total_bit_count - flip_count);
      memset(R, bit_position = flip_count = total_bit_count = 0, sizeof(R));
      count = 0;
    }
    bit_position++;
  }
  return 0;
}