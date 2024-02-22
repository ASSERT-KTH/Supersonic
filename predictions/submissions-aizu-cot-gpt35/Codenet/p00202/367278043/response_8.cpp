#include <algorithm>
#include <stdio.h>
using namespace std;
int n, x, a[30];
bool prime[1000001];

// Function to check if a number is prime
bool isPrime(int num) {
  if (num < 2) {
    return false;
  }
  if (num == 2) {
    return true;
  }
  if (num % 2 == 0) {
    return false;
  }
  for (int i = 3; i * i <= num; i += 2) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  for (int i = 0; i <= 1000000; i++) {
    prime[i] = isPrime(i);
  }

  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    sort(a, a + n);

    for (int i = 1; i <= x; i++) {
      bool found = false;
      for (int j = 0; j < n && i >= a[j]; j++) {
        if (i % a[j] == 0 && prime[i / a[j]]) {
          printf(i ? "%d\n" : "NA\n", i);
          found = true;
          break;
        }
      }
      if (found) {
        break;
      }
    }
  }
}