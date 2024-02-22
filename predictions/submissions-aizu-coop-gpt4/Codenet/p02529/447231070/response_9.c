#include <stdio.h>
#include <stdlib.h>

int main() {
  int a, b, d = 0, max_b = -1000000, min_b = 1000000;
  int *nums, *c;

  scanf("%d", &a);
  nums = (int *)malloc(a * sizeof(int));
  for (int i = 0; i < a; i++) {
    scanf("%d", &b);
    nums[i] = b;
    if (b > max_b) max_b = b;
    if (b < min_b) min_b = b;
  }

  c = (int *)calloc(max_b - min_b + 1, sizeof(int));
  for (int i = 0; i < a; i++) {
    c[nums[i] - min_b] = 1;
  }

  scanf("%d", &a);
  for (int i = 0; i < a; i++) {
    scanf("%d", &b);
    d += c[b - min_b];
  }

  printf("%d\n", d);

  free(nums);
  free(c);
  return 0;
}