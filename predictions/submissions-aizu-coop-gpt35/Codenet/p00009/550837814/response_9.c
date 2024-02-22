#include <math.h>
#include <stdio.h>
#include <bitset>

constexpr int MAX_NUM = 1000000;

int main() {
  int i, j;
  int n;
  std::bitset<MAX_NUM> prime_flags;
  
  // Mark all numbers as prime initially
  prime_flags.set();
  
  // Mark 0 and 1 as non-prime
  prime_flags[0] = prime_flags[1] = 0;
  
  int sqrt_limit = sqrt(MAX_NUM);
  for (i = 2; i <= sqrt_limit; i++) {
    if (prime_flags[i] == 1) {
      for (j = i * i; j < MAX_NUM; j += i)
        prime_flags[j] = 0;
    }
  }
  
  // Sum up the prime flags
  for (i = 2; i < MAX_NUM; i++) {
    prime_flags[i] += prime_flags[i - 1];
  }
  
  for (; scanf("%d", &n) != EOF;) {
    printf("%d\n", prime_flags[n]);
  }
  
  return 0;
}