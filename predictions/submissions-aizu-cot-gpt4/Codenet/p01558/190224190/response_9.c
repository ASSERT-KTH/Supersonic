#include <stdio.h>
long long calculate_mod(char *str, long long a, long long M, long long* d, long long* k) {
  long long result = 0;
  k[0] = 1;
  for (int j = d[0] = 0; str[j]; j++) {
    d[j + 1] = (d[j] * a + (str[j] - 'a' + 1)) % M;
    k[j + 1] = (k[j] * a) % M;
    result = (result * a + (str[j] - 'a' + 1)) % M;
  }
  return result;
}
int main() {
  int distinct_strings = 0, m, l = 0, r = 1;
  char s[300010], q[5];
  long long a[2] = {101, 103};
  long long M[2] = {1e9 + 7, 1e9 + 9};
  long long d[2][300010], k[2][300010];
  scanf("%*d %d %s", &m, s);
  long long h[2] = {calculate_mod(s, a[0], M[0], d[0], k[0]), calculate_mod(s, a[1], M[1], d[1], k[1])};
  for (int i = 0; i < m; i++) {
    scanf("%s", q);
    if (q[0] == 'L')
      l += q[1] - '-' ? 1 : -1;
    else
      r += q[1] - '-' ? 1 : -1;
    long long h1 = (M[0] * M[0] + d[0][r] - d[0][l] * k[0][r - l]) % M[0];
    long long h2 = (M[1] * M[1] + d[1][r] - d[1][l] * k[1][r - l]) % M[1];
    distinct_strings += (h1 != h[0] || h2 != h[1]);
  }
  printf("%d\n", distinct_strings);
  return 0;
}