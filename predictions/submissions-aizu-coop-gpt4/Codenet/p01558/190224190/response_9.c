#include <stdio.h>
long long a[2] = {101, 103};
long long M[2] = {1e9 + 7, 1e9 + 9};
long long d[2][300010], k[2][300010];
long long R = 1, C = 1, H[2000010], N[2000010], h[300010];
int hyouka(int a, int b) {
  if (C < b)
    return 1;
  if (C < a || b == 0)
    return 0;
  return N[H[a]] < N[H[b]] || N[H[a]] == N[H[b]] && h[H[a]] < h[H[b]] ? 1 : 0;
}
void hin(long long a) {
  int i = C++, half;
  N[H[0] = R] = a;
  while (i > 1) {
    half = i / 2;
    if(!hyouka(0, half)) break;
    H[i] = H[half];
    i = half;
  }
  H[i] = R++;
}
// ... Rest of the code follows with similar changes