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
    int p[n + 2];
    p[0] = 0;
    for (int i = 1; i < n; i += 2) {
      p[i] = i / 2 + 1;
      p[i + 1] = n - p[i];
    }
    for (int i = 0; i < k * (n - 1); i++) {
      if (i != 0 && i % (n - 1) == 0)
        printf("\n");
      int j = i % (n - 1);
      int a = (p[j] + i / (n - 1)) % n + 1;
      int b = (p[j + 1] + i / (n - 1)) % n + 1;
      printf("%d %d\n", a, b);
    }
  }
}