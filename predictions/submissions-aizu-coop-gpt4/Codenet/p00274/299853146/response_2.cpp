#include <stdio.h>

inline void process_sequence(int n, int *zero_count, int *flg) {
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d", &k);
    if (k == 0) {
      (*zero_count)++;
    }
    if (k >= 2) {
      *flg = 1;
      break;
    }
  }
}

int main(void) {
  while (1) {
    int n;
    scanf("%d", &n);
    if (n == 0)
      break;
    int zero_count = 0, flg = 0;
    process_sequence(n, &zero_count, &flg);
    if (flg == 1) {
      printf("%d\n", n - zero_count + 1);
    } else {
      printf("NA\n");
    }
  }
  return 0;
}