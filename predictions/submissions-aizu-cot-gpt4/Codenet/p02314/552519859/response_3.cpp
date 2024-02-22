#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int c[21];
  int mini[50001];
  for (int i = 1; i <= m; i++) {
    scanf("%d", &c[i]);
  }
  sort(c + 1, &c[1] + m);
  fill_n(mini + 1, n, INF);
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= n - c[i]; j++) {
      mini[j + c[i]] = min(mini[j] + 1, mini[j + c[i]]);
    }
  }
  printf("%d\n", mini[n]);
  return 0;
}