#include <stdio.h>
#include <stdlib.h>

int main() {
  int a, b, d = 0;
  int* c;

  scanf("%d", &b);

  c = (int*)malloc(b * sizeof(int));
  if (c == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }

  for (a = b; a--; ) {
    scanf("%d", &c[b]);
    d += c[b];
  }

  printf("%d\n", d);

  free(c);

  return 0;
}