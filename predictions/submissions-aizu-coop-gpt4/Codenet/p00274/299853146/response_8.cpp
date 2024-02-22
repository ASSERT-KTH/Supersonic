#include <stdio.h>
#include <stdbool.h>

int main(void) {
  int num_elements, num_non_zeros, current_num, zero_count, i;
  bool num_greater_than_one_exists;

  while (1) {
    num_greater_than_one_exists = false;
    zero_count = 0;

    scanf("%d", &num_elements);
    if (num_elements == 0)
      break;

    for (i = 0; i < num_elements; i++) {
      scanf("%d", &current_num);
      if (current_num == 0) {
        zero_count++;
      }
      if (current_num >= 2) {
        num_greater_than_one_exists = true;
      }
    }

    num_non_zeros = num_elements - zero_count;
    if (num_greater_than_one_exists) {
      printf("%d\n", num_non_zeros + 1);
    } else {
      printf("NA\n");
    }
  }
  return 0;
}