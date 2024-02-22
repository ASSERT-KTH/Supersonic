#include <stdio.h>

void hin(int* R, int* C, int* H, int* N, long long a, long long M, long long* h, long long a_val, long long M_val) {
  int i = (*C)++;
  for (N[H[0] = (*R)] = a_val; i > 0 && (N[H[i / 2]] > N[a_val] || (N[H[i / 2]] == N[a_val] && h[H[i / 2]] > h[a_val])); i /= 2)
    H[i] = H[i / 2];
  H[i] = (*R)++;
}

int hout(int* R, int* C, int* H, int* N, long long* h) {
  int rt = H[1], i, j = 2, k = H[--(*C)];
  for (i = 1; i <= (*C) && (N[H[i]] > N[k] || (N[H[i]] == N[k] && h[H[i]] > h[k])); i = j)
    H[i] = H[j = i * 2 + (N[H[i * 2]] > N[H[i * 2 + 1]])];
  H[j / 2] = k;
  return rt;
}

void init(char *s, long long a[], long long M[], long long d[][300010], long long k[][300010]) {
  int i, j;
  for (i = 0; i < 2; i++) {
    k[i][0] = 1;
    for (j = d[i][0] = 0; s[j]; j++) {
      d[i][j + 1] = (d[i][j] * a[i] + (s[j] - 'a' + 1)) % M[i];
      k[i][j + 1] = (k[i][j] * a[i]) % M[i];
    }
  }
}

long long getlr(int l, int r, int i, long long a[], long long M[], long long d[][300010], long long k[][300010]) {
  return (M[i] * M[i] + d[i][r] - d[i][l] * k[i][r - l]) % M[i];
}

void gets(char *s, long long a[], long long k[][300010], int* h) {
  int i, j;
  for (i = 0; i < 2; i++) {
    for (j = h[i] = 0; s[j]; j++)
      h[i] += k[i][j] * (s[j] - '0');
  }
}

int match(int l, int r, int* h, long long a[], long long M[], long long d[][300010], long long k[][300010]) {
  int i, j = 1;
  for (i = 0; i < 2; i++)
    j *= getlr(l, r, i, a, M, d, k) - h[i] ? 1 : 0;
  return j;
}

int main() {
  int R = 1, C = 1, H[2000010], N[2000010], h[300010];
  long long a[2] = {101, 103};
  long long M[2] = {1000000007, 1000000009};
  long long d[2][300010], k[2][300010];

  int n = 0, m, a_val, b, i, j, l = 0, r = 1;
  char s[300010], q[5];
  scanf("%*d %d %s", &m, s);

  init(s, a, M, d, k);

  for (i = 0; i < m; i++) {
    scanf("%s", q);
    if (q[0] == 'L')
      l += q[1] - '-' ? 1 : -1;
    else
      r += q[1] - '-' ? 1 : -1;
    a_val = getlr(l, r, 0, a, M, d, k);
    hin(&R, &C, H, N, a[1], M[1], h, a_val, getlr(l, r, 1, a, M, d, k));
  }

  a_val = hout(&R, &C, H, N, h);
  for (i = 1; i < m; i++) {
    b = hout(&R, &C, H, N, h);
    if (N[b] == N[a_val] && h[b] == h[a_val])
      n++;
    a_val = b;
  }

  printf("%d\n", m - n);
  return 0;
}