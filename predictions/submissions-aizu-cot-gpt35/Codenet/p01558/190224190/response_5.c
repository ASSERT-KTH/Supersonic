#include <stdio.h>
#define MAX_LEN 300010

long long a[2] = {101, 103};
long long M[2] = {1e9 + 7, 1e9 + 9};
long long d[2][MAX_LEN], k[2][MAX_LEN];
long long C = 1, H[MAX_LEN], h[MAX_LEN];

int hyouka(int a, int b) {
  return N[H[a]] < N[H[b]] || (N[H[a]] == N[H[b]] && h[H[a]] < h[H[b]]);
}

void hin(long long a) {
  int i = C++;
  while (i > 1 && hyouka(0, i / 2)) {
    H[i] = H[i / 2];
    i /= 2;
  }
  H[i] = C - 1;
}

int hout() {
  int rt = H[1], i, j = 2, last = H[--C];
  while (j <= C) {
    if (j < C && hyouka(j + 1, j)) {
      j++;
    }
    if (!hyouka(j, C)) {
      break;
    }
    H[j / 2] = H[j];
    j = j * 2 + 1 - hyouka(j * 2, j * 2 + 1);
  }
  H[j / 2] = last;
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
  long long len = r - l + 1;
  return (M[i] * M[i] + d[i][r] - d[i][l - 1] * k[i][len]) % M[i];
}

void gets(char *s, int *h) {
  int i;
  for (i = 0; i < 2; i++) {
    int len = 0;
    h[i] = 0;
    while (s[len]) {
      h[i] = (h[i] * a[i] + (s[len] - 'a' + 1)) % M[i];
      len++;
    }
  }
}

int main() {
  int n = 0, m, a, b, i, l = 0, r = 1;
  char s[MAX_LEN], q[5];
  scanf("%*d %d %s", &m, s);
  init(s);
  for (i = 0; i < m; i++) {
    scanf("%s", q);
    if (q[0] == 'L') {
      l += (q[1] != '-');
    } else {
      r += (q[1] != '-');
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