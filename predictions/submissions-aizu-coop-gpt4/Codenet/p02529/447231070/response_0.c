#include <stdio.h>
#include <stdlib.h>

int main() {
  int a, b, d = 0, max = 0;
  int *c;

  scanf("%d", &a);
  int* firstSeries = (int*)malloc(a * sizeof(int));

  for (int i = 0; i < a; i++) {
    scanf("%d", &firstSeries[i]);
    if (firstSeries[i] < 0) {
      printf("Negative numbers not allowed.\n");
      return 1;
    }
    if (firstSeries[i] > max) {
      max = firstSeries[i];
    }
  }

  c = (int*)calloc(max + 1, sizeof(int));

  for (int i = 0; i < a; i++) {
    c[firstSeries[i]] = 1;
  }

  free(firstSeries);

  scanf("%d", &a);
  for (int i = 0; i < a; i++) {
    scanf("%d", &b);
    if (b < 0) {
      printf("Negative numbers not allowed.\n");
      return 1;
    }
    if (b <= max) {
      d += c[b];
    }
  }

  printf("%d\n", d);
  free(c);
  return 0;
}