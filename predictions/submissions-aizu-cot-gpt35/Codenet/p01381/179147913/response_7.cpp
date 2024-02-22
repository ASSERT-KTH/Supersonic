#include <cstdio>
using namespace std;

int main() {
  int n, k;
  while (scanf("%d %d", &n, &k) == 2) {
    if (n / 2 < k) {
      printf("-1\n");
    }
    else {
      int p[n + 2];
      p[0] = 0;
      for (int i = 1; i < n; i += 2) {
        p[i] = i / 2 + 1;
        p[i + 1] = n - p[i];
      }
      for (int i = 0; i < k; i++) {
        if (i != 0)
          printf("\n");
        int a, b;
        for (int j = 0; j < n - 1; j++) {
          a = (p[j] + i) % n + 1;
          b = (p[j + 1] + i) % n + 1;
          printf("%d %d\n", a, b);
        }
      }
    }
  }
  return 0;
}