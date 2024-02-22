#include <cstdio>

int main() {
  int n, k;
  while (scanf("%d %d", &n, &k) == 2) {
    if (n / 2 < k) {
      puts("-1");
      continue;
    }

    int p[n + 2];
    p[0] = 0;
    for (int i = 1; i < n; i += 2) {
      p[i] = i / 2 + 1;
      p[i + 1] = n - p[i];
    }

    for (int i = 0; i < n - 1; i++) {
      int a = (p[i] + k - 1) % n + 1;
      int b = (p[i + 1] + k - 1) % n + 1;
      printf("%d %d\n", a, b);
    }
  }
  return 0;
}