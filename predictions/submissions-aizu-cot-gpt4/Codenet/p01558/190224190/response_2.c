#include <stdio.h>
#define SIZE 300010
#define MAGNITUDE 2000010
long long a[2] = {101, 103};
long long M[2] = {1e9 + 7, 1e9 + 9};
long long d[2][SIZE], k[2][SIZE];
long long R = 1, C = 1, H[MAGNITUDE], N[MAGNITUDE], h[SIZE];
bool hyouka(int a, int b) {
  if (C < b)
    return true;
  if (C < a || b == 0)
    return false;
  return N[H[a]] < N[H[b]] || (N[H[a]] == N[H[b]] && h[H[a]] < h[H[b]]);
}
void hin(long long a) {
  int i = ++C;
  for (N[H[0] = R] = a; hyouka(0, i >> 1); i >>= 1)
    H[i] = H[i >> 1];
  H[i] = R++;
}
int hout() {
  int rt = H[1], i, j = 2, k = H[C--];
  for (i = 1; hyouka(i, C); i = j)
    H[i] = H[j = (i << 1) + 1 - hyouka(i << 1, (i << 1) + 1)];
  H[j >> 1] = k;
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
int getlr(int l, int r, int i) {
  return (M[i] * M[i] + d[i][r] - d[i][l] * k[i][r - l]) % M[i];
}
void gets(char *s, int *h) {
  int i, j;
  for (i = 0; i < 2; i++) {
    for (j = h[i] = 0; s[j]; j++)
      h[i] += k[i][j] * (s[j] - '0');
  }
}
bool match(int l, int r, int *h) {
  int i;
  bool j = true;
  for (i = 0; i < 2; i++)
    j *= getlr(l, r, i) != h[i];
  return j;
}
int main() {
  int n = 0, m, a, b, i, l = 0, r = 1;
  char s[SIZE], q[5];
  scanf("%*d %d %s", &m, s);
  init(s);
  for (i = 0; i < m; i++) {
    scanf("%s", q);
    l += q[1] == '-' ? -1 : 1;
    r += q[1] == '-' ? -1 : 1;
    h[R] = getlr(l, r, 0);
    hin(getlr(l, r, 1));
  }
  a = hout();
  for (i = 1; i < m; i++) {
    b = hout();
    if (N[b] == N[a] && h[b] == h[a])
      n++;
    a = b;
  }
  printf("%d\n", m - n);
  return 0;
}