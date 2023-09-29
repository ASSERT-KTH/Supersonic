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
    for (int i = 0; i < k; i++) {
      if (i != 0)
        printf("\n");
      for (int j = 0; j < n - 1; j++) {
        printf("%d %d\n", p[j] + i, p[j + 1] + i);
      }
    }
  }
}
