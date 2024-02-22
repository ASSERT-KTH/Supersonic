#include <algorithm>
#include <stdio.h>
#include <set>
using namespace std;
int n, x, a[30];
set<int> prime_sums;
bool prime[1000001];

void sieve() {
  prime[0] = false, prime[1] = false, prime[2] = true;
  for (int i = 3; i <= x; i += 2)
    prime[i] = true;
  for (int i = 3; i * i <= x; i++) {
    if (!prime[i])
      continue;
    for (int j = i; i * j <= x; j += 2)
      prime[i * j] = false;
  }
}

int main() {
  #pragma GCC optimize("Ofast")
  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    sort(a, a + n);
    prime_sums.clear();
    prime_sums.insert(0);
    int max_prime_sum = 0;
    sieve();
    for (int i = 1; i <= x; i++) {
      for (int j = 0; j < n && i >= a[j]; j++) {
        if (prime_sums.count(i - a[j])) {
          prime_sums.insert(i);
          if (prime[i])
            max_prime_sum = i;
          break;
        }
      }
    }
    printf(max_prime_sum ? "%d\n" : "NA\n", max_prime_sum);
  }
}