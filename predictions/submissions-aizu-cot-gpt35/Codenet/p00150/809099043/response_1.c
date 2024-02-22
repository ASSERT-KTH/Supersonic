#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;
  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  }
  return true;
}

int main() {
  int n, p, q;
  scanf("%d", &n);
  
  while (n != 0) {
    for (int i = n; i >= 5; i--) {
      if (isPrime(i) && isPrime(i - 2)) {
        p = i - 2;
        q = i;
        break;
      }
    }
    printf("%d %d\n", p, q);
    scanf("%d", &n);
  }
  
  return 0;
}