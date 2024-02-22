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
    for (int i = 0; i < k; i++) {
      if (i != 0)
        printf("\n");
      for (int j = 0; j < n - 1; j++) {
        int a = (j/2 + 1 + i) % n + 1;
        int b = (n - (j/2 + 1) + i) % n + 1;
        printf("%d %d\n", a, b);
      }
    }
  }
}