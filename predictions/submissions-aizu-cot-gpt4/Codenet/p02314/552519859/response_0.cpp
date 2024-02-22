#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 2000000000;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int c[21];
  int mini[50001];
  for (int i = 1; i <= m; i++) {
    scanf("%d", &c[i]);
  }
  sort(c + 1, c + 1 + m);
  fill_n(mini + 1, n, INF); // initialize mini[] array with INF
  mini[0] = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= n - c[i]; j++) {
      int next = j + c[i];
      mini[next] = min(mini[j] + 1, mini[next]); // Use a temporary variable to reduce calculations
    }
  }
  printf("%d\n", mini[n]);
  return 0;
}