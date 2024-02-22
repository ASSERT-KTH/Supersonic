#include <stdio.h>
#include <math.h>
#include <vector>

bool isprime1(int n) {
  if (n <= 1) {
    return false;
  }
  if (n == 2) {
    return true;
  }
  if (n % 2 == 0) {
    return false;
  }
  for (int i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

std::vector<bool> generate_primes(int n) {
  std::vector<bool> primes(n + 1, true);
  primes[0] = primes[1] = false;
  for (int p = 2; p*p <= n; p++) {
    if (primes[p] == true) {
      for (int i = p*p; i <= n; i += p) {
        primes[i] = false;
      }
    }
  }
  return primes;
}

int main() {
  int n, p, q;
  while (1) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    std::vector<bool> primes = generate_primes(n);
    for (int i = n; i >= 5; i--) {
      if (primes[i] == true && primes[i - 2] == true) {
        p = i - 2;
        q = i;
        break;
      }
    }
    printf("%d %d\n", p, q);
  }
  return 0;
}