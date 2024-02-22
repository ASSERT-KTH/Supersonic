#include <stdio.h>

// Use constants instead of magic numbers
const long long MOD1 = 1e9 + 7;
const long long MOD2 = 1e9 + 9;

// Rename function and add comments
// This function calculates the hash value for a given string
void calculateHash(char *s, long long* d, long long* k, long long* a, long long* M) {
  int i, j;
  for (i = 0; i < 2; i++) {
    k[i][0] = 1;
    for (j = d[i][0] = 0; s[j]; j++) {
      d[i][j + 1] = (d[i][j] * a[i] + (s[j] - 'a' + 1)) % M[i];
      k[i][j + 1] = (k[i][j] * a[i]) % M[i];
    }
  }
}

// ...

int main() {
  long long a[2] = {101, 103};
  long long M[2] = {MOD1, MOD2};
  long long d[2][300010], k[2][300010];

  // ...

  // Use local variable instead of global
  char s[300010];

  // ...

  // Pass local variables as arguments to function
  calculateHash(s, d, k, a, M);

  // ...
}