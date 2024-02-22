#include <stdio.h>

int a[2] = {101, 103};
int M[2] = {1000000007, 1000000009};
int d[2][300010], k[2][300010];
int R = 1, C = 1, H[2000010], N[2000010], h[300010];

int hyouka(int a, int b) {
  if (C < b)
    return 1;
  if (C < a || b == 0)
    return 0;
  if (N[H[a]] < N[H[b]])
    return 1;
  if (N[H[a]] == N[H[b]] && h[H[a]] < h[H[b]])
    return 1;
  return 0;
}

void hin(int a) {
  int i = C++;
  while (i > 1 && hyouka(0, i / 2)) {
    H[i] = H[i / 2];
    i /= 2;
  }
  H[i] = R++;
}

int hout() {
  int rt = H[1], i, j, k;
  k = H[--C];
  for (i = 1; hyouka(i, C); i = j) {
    j = i * 2 + 1 - hyouka(i * 2, i * 2 + 1);
    H[i] = H[j];
  }
  H[j / 2] = k;
  return rt;
}

void init(char *s) {
  int i, j;
  for (i = 0; i < 2; i++) {
    k[i][0] = 1;
    d[i][0] = 0;
    for (j = 0; s[j]; j++) {
      d[i][j + 1] = (d[i][j] * a[i] + (s[j] - 'a' + 1)) % M[i];
      k[i][j + 1] = (k[i][j] * a[i]) % M[i];
    }
  }
}

void gets(char *s, int *h) {
  int i, j;
  for (i = 0; i < 2; i++) {
    for (j = h[i] = 0; s[j]; j++) {
      h[i] += k[i][j] * (s[j] - '0');
    }
  }
}

int match(int l, int r, int *h) {
  int i;
  for (i = 0; i < 2; i++) {
    if (getlr(l, r, i) != h[i]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int n = 0, m, a, b, i, j, l = 0, r = 1;
  char s[300010], q[5];
  scanf("%d %s", &m, s);
  init(s);
  for (i = 0; i < m; i++) {
    scanf("%s", q);
    if (q[0] == 'L') {
      l += q[1] - '-' ? 1 : -1;
    } else {
      r += q[1] - '-' ? 1 : -1;
    }
    h[R] = getlr(l, r, 0);
    hin(getlr(l, r, 1));
  }
  a = hout();
  for (i = 1; i < m; i++) {
    b = hout();
    if (N[b] == N[a] && h[b] == h[a]) {
      n++;
    }
    a = b;
  }
  printf("%d\n", m - n);
  return 0;
}