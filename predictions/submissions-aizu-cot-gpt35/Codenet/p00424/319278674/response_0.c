#include <stdio.h>
#include <string.h>

int main() {
  int n;
  scanf("%d", &n);

  while (n) {
    int *t = (int*)malloc(n * sizeof(int));
    memset(t, 0, n * sizeof(int));

    char input[2 * n + 1];
    scanf("%s", input);

    int index = 0;
    for (int i = 0; i < n; i++) {
      sscanf(&input[index], " %c %c", &index, &t[i]);
    }

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
      putchar(!t[i] * i + t[i]);
    }

    free(t);
  }

  return 0;
}