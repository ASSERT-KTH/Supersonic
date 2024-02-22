#include <stdio.h>
#include <stdlib.h>

int main() {
  char* t = NULL;
  int n = 0, i = 0;

  while (scanf("%d", &n) == 1) {
    t = realloc(t, n * sizeof(char));  // Dynamically allocate memory based on input size

    for (i = 0; i < n; i++)
      scanf(" %c", &t[i]);

    for (i = 0; i < n; i++) {
      char output = !t[i] * i + t[i];
      putchar(output);
      putchar('\n');
    }
  }

  free(t);  // Free allocated memory
  return 0;
}