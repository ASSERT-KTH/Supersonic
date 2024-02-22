#include <stdio.h>
long long a[2] = {101, 103};
long long M[2] = {1e9 + 7, 1e9 + 9};
long long d[2][300010], k[2][300010];
long long R = 1, C = 1, H[2000010], N[2000010], h[300010];

int hyouka(int a, int b) {
  if (C < a || C < b || b == 0)
    return 0;
  return N[H[a]] < N[H[b]] || N[H[a]] == N[H[b]] && h[H[a]] < h[H[b]] ? 1 : 0;
}
void hin(long long a) {
  int i = C++;
  for (N[H[0] = R] = a; hyouka(0, i >> 1); i >>= 1)
    H[i] = H[i >> 1];
  H[i] = R++;
}
int hout() {
  int rt = H[1], i;
  int j = 2, k = H[--C];
  for (i = 1; hyouka(i, C); i = j)
    H[i] = H[j = i << 1 + 1 - hyouka(i << 1, i << 1 + 1)];
  H[j >> 1] = k;
  return rt;
}
void init(char *s) {
  int i, j;
  for (i = 0; i < 2; i++) {
    k[i][0] = 1;
    for (j = d[i][0] = 0; s[j]; ++j) {
      d[i][j + 1] = (d[i][j] * a[i] + (s[j] - 'a' + 1)) % M[i];
      k[i][j + 1] = (k[i][j] * a[i]) % M[i];
    }
  }
}
int getlr(int l, int r, int i) {
  return (M[i] * M[i] + d[i][r] - d[i][l] * k[i][r - l]) % M[i];
}
void gets(char *s, int *h) {
  int i, j;
  for (i = 0; i < 2; i++) {
    for (j = h[i] = 0; s[j]; ++j)
      h[i] += k[i][j] * (s[j] - '0');
  }
}
int match(int l, int r, int *h) {
  int i, j = 1;
  for (i = 0; i < 2; i++)
    j *= getlr(l, r, i) - h[i] ? 1 : 0;
  return j;
}
int main() {
  int n = 0, m, a, b, i, l = 0, r = 1;
  char s[300010], q[5];
  scanf("%*d %d %s", &m, s);
  init(s);
  for (i = 0; i < m; ++i) {
    scanf("%s", q);
    if (q[0] == 'L')
      l += q[1] - '-' ? 1 : -1;
    else
      r += q[1] - '-' ? 1 : -1;
    long long res = getlr(l, r, 0);
    h[R] = res;
    hin(res);
  }
  a = hout();
  for (i = 1; i < m; ++i) {
    b = hout();
    if (N[b] == N[a] && h[b] == h[a])
      n++;
    a = b;
  }
  printf("%d\n", m - n);
  return 0;
}