#include <stdio.h>

#define SIZE 300010
#define MODULO1 1000000007
#define MODULO2 1000000009

int a[2] = {101, 103};
int M[2] = {MODULO1, MODULO2};
int d[2][SIZE], k[2][SIZE];
int R = 1, C = 1, H[2000010], N[2000010], h[SIZE];

int hyouka(int a, int b) {
  if (C < b)
    return 1;
  if (C < a || b == 0)
    return 0;
  return N[H[a]] < N[H[b]] || N[H[a]] == N[H[b]] && h[H[a]] < h[H[b]] ? 1 : 0;
}

void init(char *s) {
  int i, j;
  for (i = 0; i < 2; i++) {
    k[i][0] = 1;
    for (j = d[i][0] = 0; s[j]; j++) {
      int to_add = s[j] - 'a' + 1;
      d[i][j + 1] = (d[i][j] * a[i] + to_add) % M[i];
      k[i][j + 1] = (k[i][j] * a[i]) % M[i];
    }
  }
}

// Rest of the code...

int main() {
  // Code...

  return 0;
}