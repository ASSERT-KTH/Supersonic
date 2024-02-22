#include <stdio.h>
int main(void) {
  int n, k;
  while (1) {
    int count = 0;
    bool found = false;
    scanf("%d", &n);
    if (n == 0)
      break;
    for (int i = 0; i < n - 1; i += 2) {
      scanf("%d %d", &k, &k);
      if (k != 0)
        count += 2;
      if (k >= 2)
        found = true;
    }
    if (n % 2 == 1) { // Handle the case when n is odd
      scanf("%d", &k);
      if (k != 0)
        count++;
      if (k >= 2)
        found = true;
    }
    if (found)
      printf("%d\n", count);
    else
      printf("NA\n");
  }
  return 0;
}