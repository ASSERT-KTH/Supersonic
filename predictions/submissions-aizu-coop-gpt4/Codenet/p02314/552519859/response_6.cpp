#include <algorithm>
#include <cstdio>
#include <math.h>
using namespace std;
const int INF = 2000000000;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);  // Faster I/O operation
  int c[21];
  int mini[50001];
  for (int i = 1; i <= m; i++) {
    scanf("%d", &c[i]);  // Faster I/O operation
  }
  sort(c + 1, c + 1 + m);
  for (int i = 1; i <= n; i++)
    mini[i] = INF;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= n - c[i]; j++) {
      int temp = j + c[i];  // Avoiding redundant computation
      int minj = mini[j];  // Reducing memory access
      mini[temp] = min(minj + 1, mini[temp]);
    }
  }
  printf("%d\n", mini[n]);  // Faster I/O operation
  return 0;
}