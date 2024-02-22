#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int n, k;
  int p[100005]; // Assuming maximum value of n is 100000
  while (cin >> n >> k) {
    if (n / 2 < k) {
      puts("-1");
      continue;
    }
    p[0] = 0;
    for (int i = 1; i < n; i += 2) {
      p[i] = i / 2 + 1;
      p[i + 1] = n - p[i];
    }
    for (int i = 0; i < k; i++) {
      if (i != 0)
        puts("");
      for (int j = 0; j < n - 1; j++) {
        int a = p[j] + i + 1;
        int b = p[j + 1] + i + 1;
        printf("%d %d\n", a, b);
      }
    }
  }
}