#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

std::vector<bool> primes;

void sieve(int n) {
  primes = std::vector<bool>(n+1, true);
  primes[0] = primes[1] = false;
  for (int p=2; p*p<=n; p++) {
    if (primes[p] == true) {
      for (int i=p*p; i<=n; i += p)
        primes[i] = false;
    }
  }
}

bool isprime1(int n) {
  return primes[n];
}

int main() {
  int n, p, q;
  scanf("%d", &n);
  sieve(n);
  while (1) {
    if (n == 0)
      break;
    for (int i = n; i >= 5; i--) {
      if (isprime1(i) && isprime1(i - 2)) {
        p = i - 2;
        q = i;
        break;
      }
    }
    printf("%d %d\n", p, q);
    scanf("%d", &n);
    if (n > primes.size()) {
      sieve(n);
    }
  }
  return 0;
}