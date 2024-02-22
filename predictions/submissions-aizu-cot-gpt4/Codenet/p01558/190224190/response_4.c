#include <stdio.h>
long long a[2] = {101, 103};
long long M[2] = {1e9 + 7, 1e9 + 9};
long long *d[2], *k[2], *H, *N, *h;
long long R = 1, C = 1;
int hyouka(int a, int b) {
  if (C < b)
    return 1;
  if (C < a || b == 0)
    return 0;
  return N[H[a]] < N[H[b]] || N[H[a]] == N[H[b]] && h[H[a]] < h[H[b]] ? 1 : 0;
}
inline void hin(long long a) {
  int i = C++;
  for (N[H[0] = R] = a; hyouka(0, i / 2); i /= 2)
    H[i] = H[i / 2];
  H[i] = R++;
}
inline int hout() {
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
  }
}
inline int getlr(int l, int r, int i) {
  return (M[i] * M[i] + d[i][r] - d[i][l] * k[i][r - l]) % M[i];
}
inline int match(int l, int r, int *h) {
  int i, j = 1;
  for (i = 0; i < 2; i++)
    j *= getlr(l, r, i) - h[i] ? 1 : 0;
  return j;
}
int main() {
  int n = 0, m, a, b, i, l = 0, r = 1;
  char s[300010], q[5];
  scanf("%*d %d %s", &m, s);
  d[0] = new long long[m+1];
  d[1] = new long long[m+1];
  k[0] = new long long[m+1];
  k[1] = new long long[m+1];
  H = new long long[m+1];
  N = new long long[m+1];
  h = new long long[m+1];
  init(s);
  for (i = 0; i < m; i++) {
    scanf("%s", q);
    if (q[0] == 'L')
      l += q[1] - '-' ? 1 : -1;
    else
      r += q[1] - '-' ? 1 : -1;
    long long temp = getlr(l, r, 0);
    h[R] = temp;
    hin(temp);
  }
  a = hout();
  for (i = 1; i < m; i++) {
    b = hout();
    if (N[b] == N[a] && h[b] == h[a])
      n++;
    a = b;
  }
  printf("%d\n", m - n);
  delete[] d[0];
  delete[] d[1];
  delete[] k[0];
  delete[] k[1];
  delete[] H;
  delete[] N;
  delete[] h;
  return 0;
}