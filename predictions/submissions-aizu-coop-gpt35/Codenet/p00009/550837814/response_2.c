#include <math.h>
#include <stdio.h>
#include <bitset>

int main() {
  int i, j;
  int n;
  std::bitset<1000000> num;

  for (i = 0; i < 1000000; i++) {
    num[i] = 1;
  }
  num[0] = num[1] = 0;

  for (i = 3; i < sqrt(1000000); i += 2) {
    if (num[i] == 1) {
      for (j = i * i; j < 1000000; j += 2 * i) {
        num[j] = 0;
      }
    }
  }

  for (; scanf("%d", &n) != EOF;) {
    printf("%d\n", num[n]);
  }

  return 0;
}