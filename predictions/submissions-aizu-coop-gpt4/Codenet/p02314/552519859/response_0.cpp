#include <cstdio>
#include <algorithm>
#include <math.h>
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
  fill(mini, mini+n+1, INF); // initialize mini array with INF
  mini[0] = 0; // base case
  for (int i = 1; i <= m; i++) {
    for (int j = c[i]; j <= n; j++) {
      mini[j] = min(mini[j], mini[j - c[i]] + 1);
    }
  }
  printf("%d\n", mini[n]);
  return 0;
}