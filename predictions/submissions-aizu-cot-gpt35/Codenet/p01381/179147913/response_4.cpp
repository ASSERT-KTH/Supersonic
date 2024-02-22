#include <cstdio>

int main() {
  int n, k;
  while (scanf("%d %d", &n, &k) == 2) {
    if (n / 2 < k) {
      putchar('-');
      putchar('1');
      putchar('\n');
      continue;
    }
    int p[n + 2];
    for (int i = 1; i < n; i += 2) {
      p[i] = i / 2 + 1;
      p[i + 1] = n - p[i];
    }
    for (int i = 0; i < k; i++) {
      if (i != 0)
        putchar('\n');
      for (int j = 0; j < n - 1; j++) {
        int a = p[j] + i + 1;
        int b = p[j + 1] + i + 1;
        printf("%d %d\n", a, b);
      }
    }
  }
}