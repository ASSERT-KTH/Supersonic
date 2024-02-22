#include <stdio.h>

constexpr long long a[2] = {101, 103};
constexpr long long M[2] = {1e9 + 7, 1e9 + 9};
long long d[2][300010], k[2][300010];
long long R = 1, C = 1, H[2000010], N[2000010], h[300010];

bool evaluate(int a, int b) {
  if (C < b) return true;
  if (C < a || b == 0) return false;
  return N[H[a]] < N[H[b]] || (N[H[a]] == N[H[b]] && h[H[a]] < h[H[b]]);
}

void insert(long long a) {
  auto i = C++;
  for (N[H[0] = R] = a; evaluate(0, i / 2); i /= 2) H[i] = H[i / 2];
  H[i] = R++;
}

int pop() {
  int ret = H[1], i, j = 2, k = H[--C];
  for (i = 1; evaluate(i, C); i = j) 
    H[i] = H[j = i * 2 + 1 - evaluate(i * 2, i * 2 + 1)];
  H[j / 2] = k;
  return ret;
}

void init(char *s) {
  for (auto i = 0; i < 2; i++) {
    k[i][0] = 1;
    for (auto j = d[i][0] = 0; s[j]; j++) {
      d[i][j + 1] = (d[i][j] * a[i] + (s[j] - 'a' + 1)) % M[i];
      k[i][j + 1] = (k[i][j] * a[i]) % M[i];
    }
  }
}

int getlr(int l, int r, int i) {
  return (M[i] * M[i] + d[i][r] - d[i][l] * k[i][r - l]) % M[i];
}

void gets(char *s, int *h) {
  for (auto i = 0; i < 2; i++) {
    for (auto j = h[i] = 0; s[j]; j++)
      h[i] += k[i][j] * (s[j] - '0');
  }
}

bool match(int l, int r, int *h) {
  return getlr(l, r, 0) != h[0] && getlr(l, r, 1) != h[1];
}

int main() {
  int n = 0, m, a, b, i, j, l = 0, r = 1;
  char s[300010], q[5];
  scanf("%*d %d %s", &m, s);
  init(s);
  for (i = 0; i < m; i++) {
    scanf("%s", q);
    if (q[0] == 'L') l += q[1] - '-' ? 1 : -1;
    else r += q[1] - '-' ? 1 : -1;
    h[R] = getlr(l, r, 0);
    insert(getlr(l, r, 1));
  }
  a = pop();
  for (i = 1; i < m; i++) {
    b = pop();
    if (N[b] == N[a] && h[b] == h[a]) n++;
    a = b;
  }
  printf("%d\n", m - n);
  return 0;
}