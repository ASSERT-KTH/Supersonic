#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 2000000000;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int c[21], mini[50001] = {0};
  mini[0] = INF;
  
  for (int i = 0; i < m; i++) {
    scanf("%d", &c[i]);
  }
  
  for (int i = 0; i < m; i++) {
    for (int j = c[i]; j <= n; j++) {
      mini[j] = min(mini[j], mini[j - c[i]] + 1);
    }
  }
  printf("%d\n", mini[n]);
  return 0;
}