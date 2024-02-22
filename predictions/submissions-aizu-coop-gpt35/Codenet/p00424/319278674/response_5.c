#include <stdio.h>
#include <string.h>

#define MAX_N 999

int t[MAX_N];

int main() {
  int n;
  char line[1024];

  while (fgets(line, sizeof(line), stdin) != NULL) {
    sscanf(line, "%d", &n);

    memset(t, 0, MAX_N * sizeof(int));

    for (int i = 0; i < n; i++) {
      fgets(line, sizeof(line), stdin);
      sscanf(line, " %c %c", &t[i], &t[t[i]]);
    }

    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &n);

    for (int i = 0; i < n; i++) {
      fgets(line, sizeof(line), stdin);
      putchar(!t[line[0]] * line[0] + t[line[0]]);
    }

    putchar('\n');
  }

  return 0;
}