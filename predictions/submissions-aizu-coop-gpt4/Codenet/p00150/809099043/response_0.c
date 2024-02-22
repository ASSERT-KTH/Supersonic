#include <stdio.h>
#include <math.h>

// Optimized prime checking function
int isprime1(int n) {
  if (n <= 1) return 0;
  if (n <= 3) return 1;
  
  // Optimize check for divisibility by 2 and 3
  if (n % 2 == 0 || n % 3 == 0) return 0;
  
  // Only check odd factors up to sqrt(n)
  for (int i = 5; i <= sqrt(n); i += 6) {
    if (n % i == 0 || n % (i + 2) == 0)
      return 0;
  }
  
  return 1;
}

int main() {
  int n, p, q;
  
  while (scanf("%d", &n), n != 0) { // Combine scanf and check in while loop
    // Start with n and n-2, and search downwards
    for (q = n, p = n - 2; q >= 5; q -= 2, p -= 2) {
      // Check if both numbers are prime
      if (isprime1(q) && isprime1(p)) {
        printf("%d %d\n", p, q);
        break;
      }
    }
  }
  
  return 0;
}