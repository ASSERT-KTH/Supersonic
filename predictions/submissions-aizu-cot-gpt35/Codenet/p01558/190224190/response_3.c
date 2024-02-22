#include <stdio.h>

int a[2] = {101, 103};
int M[2] = {1000000007, 1000000009};
int d[2][100010], k[2][100010];
int R = 1, C = 1, H[2000010], N[2000010], h[100010];

int hyouka(int a, int b) {
  if (C < b)
    return 1;
  if (C < a || b == 0)
    return 0;
  return N[H[a]] < N[H[b]] || (N[H[a]] == N[H[b]] && h[H[a]] < h[H[b]]);
}

void hin(int a) {
  int i = C++;
  H[i] = a;
  while (i > 1 && hyouka(i / 2, i)) {
    H[i] = H[i / 2];
    i /= 2;
  }
  H[i] = R++;
}

int hout() {
  int rt = H[1], i, j = 2, k = H[--C];
  while (j <= C) {
    if (j < C && hyouka(j + 1, j)) {
      j++;
    }
    if (!hyouka(j, i)) {
      break;
    }
    H[i] = H[j];
    i = j;
    j = i * 2;
  }
  H[i] = k;
  return rt;
}

void init(char* s, int len) {
  for (int i = 0; i < 2; i++) {
    k[i][0] = 1;
    d[i][0] = 0;
    for (int j = 0; j < len; j++) {
      d[i][j + 1] = (d[i][j] * a[i] + (s[j] - 'a' + 1)) % M[i];
      k[i][j + 1] = (k[i][j] * a[i]) % M[i];
    }
  }
}

int getlr(int l, int r, int i) {
  int kr = k[i][r - l];
  return (M[i] * M[i] + d[i][r] - d[i][l] * kr) % M[i];
}

void gets(char* s, int len, int* h) {
  for (int i = 0; i < 2; i++) {
    h[i] = 0;
    for (int j = 0; j < len; j++) {
      h[i] += k[i][j] * (s[j] - '0');
    }
  }
}

int match(int l, int r, int* h) {
  int res = 1;
  for (int i = 0; i < 2; i++) {
    int glr = getlr(l, r, i);
    res *= (glr - h[i]) ? 1 : 0;
  }
  return res;
}

int main() {
  int n = 0, m, a, b, i, j, l = 0, r = 1;
  char s[100010], q[5];
  scanf("%*d %d %s", &m, s);
  int len = strlen(s);
  init(s, len);
  for (i = 0; i < m; i++) {
    scanf("%s", q);
    if (q[0] == 'L')
      l += q[1] - '-' ? 1 : -1;
    else
      r += q[1] - '-' ? 1 : -1;
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