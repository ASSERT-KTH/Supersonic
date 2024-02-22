#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int n, k;
  while (cin >> n >> k) {
    if (n / 2 < k) {
      printf("-1\n");
      continue;
    }
    int p[n];
    p[0] = 0;
    for (int i = 1; i < n; i += 2) {
      p[i] = i / 2 + 1;
      p[i + 1] = n - p[i];
    }

    for (int i = 0; i < k; i += 4) {
      if (i != 0)
        printf("\n");

      for (int j = 0; j < n - 1; j += 2) {
        int a = (p[j] + i) % n + 1;
        int b = (p[j + 1] + i) % n + 1;
        printf("%d %d\n", a, b);

        a = (p[j] + i + 1) % n + 1;
        b = (p[j + 1] + i + 1) % n + 1;
        printf("%d %d\n", a, b);

        a = (p[j] + i + 2) % n + 1;
        b = (p[j + 1] + i + 2) % n + 1;
        printf("%d %d\n", a, b);

        a = (p[j] + i + 3) % n + 1;
        b = (p[j + 1] + i + 3) % n + 1;
        printf("%d %d\n", a, b);
      }
    }
  }
}