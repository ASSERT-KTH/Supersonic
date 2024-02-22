#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int n;
  int* t = malloc(999 * sizeof(int));

  while (scanf("%d", &n) == 1) {
    memset(t, 0, 999 * sizeof(int));

    int i;
    for (; n--; t[i] = t[i])
      scanf(" %c %c", &i, (char*)&t[i]);

    scanf("%d", &n);
    for (; n--;)
    {
      scanf(" %c", &i);
      int result = !t[i] * i + t[i];
      printf("%c", result);
    }
    printf("\n");
  }

  free(t);
  return 0;
}