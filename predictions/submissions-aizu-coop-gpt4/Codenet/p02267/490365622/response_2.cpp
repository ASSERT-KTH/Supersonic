#include <stdio.h>
#include <string.h> // for memset

int main() {
  int n, q, i, j, cnt = 0;
  int T[500];
  char exists[10001]; // Using char instead of int saves memory
  memset(exists, 0, sizeof(exists)); // Initialize all to false

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    int temp;
    scanf("%d", &temp);
    exists[temp] = 1; // Mark as present
  }

  scanf("%d", &q);

  for (j = 0; j < q; j++) {
    scanf("%d", &T[j]);
    if (exists[T[j]]) {
      cnt++;
    }
  }

  printf("%d\n", cnt);
  return 0;
}