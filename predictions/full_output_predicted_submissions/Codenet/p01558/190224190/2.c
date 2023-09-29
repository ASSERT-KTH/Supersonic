#include <stdio.h>
long long a[2] = {101, 103};
long long M[2] = {1e9 + 7, 1e9 + 9};
long long d[2][300010], k[2][300010];
long long R = 1, C = 1, H[200010], N[2000010], h[300010];
int hyouka(int a, int b) {
  if (C < b)
    return 1;
  if (C < a || b == 0)
    return 0;
  return N[H[a]] < N[H[b]] || N[H[a]] == N[H[b]] && h[H[a]] < h[H[b]] ? 1 : 0;
}
void hin(long long a) {
  int i = C++;
  for (N[H[0] = R] = a; hyouka(0, i / 2); i /= 2)
    H[i] = H[i / 2];
  H[i] = R++;
}
int hout() {
  int rt = H[1], i, j = 2, k = H[--C];
  for (i = 1; hyouka(i, C); i = j)
    H[i] = H[j = i * 2 + 1 - hyouka(i * 2, i * 2 + 1)];
  H[j / 2] = k;
  return rt;
}
void init(char *s) {
  int i, j;
  for (i = 0; i < 2; i++) {
    k[i][0] = 1;
    for (j = d[i][0] = 0; s[j]; j++) {
      d[i][j + 1] = (d[i][j] * a[i] + (s[j] - 'a' + 1)) % M[i];
      k[i][j + 1] = (k[i][j] * a[i]) % M[i];
    }
