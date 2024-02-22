#include <algorithm>
#include <iostream>
using namespace std;

const int INF = 2000000000;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  int c[m];
  for (int i = 0; i < m; i++) {
    scanf("%d", &c[i]);
  }

  // Simple sorting algorithm (bubble sort)
  for (int i = 0; i < m - 1; i++) {
    for (int j = 0; j < m - i - 1; j++) {
      if (c[j] > c[j + 1]) {
        swap(c[j], c[j + 1]);
      }
    }
  }

  int mini[n + 1];
  for (int i = 0; i <= n; i++) {
    mini[i] = INF;
  }

  for (int i = 0; i < m; i++) {
    for (int j = n - c[i]; j >= 0; j--) {
      mini[j + c[i]] = min(mini[j + c[i]], mini[j] + 1);
    }
  }

  printf("%d\n", mini[n]);

  return 0;
}