#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define REP(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define rer(i, a, b) for (int i = (int)a; i <= (int)b; ++i)
#define each(i, c)                                                             \
  for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define all(v) v.begin(), v.end()
#define mset(a, n) memset(a, n, sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int inf = 1000000000;
const int mod = 1000000007;
const double eps = 1e-9;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int main() {
  int e;
  while (scanf("%d", &e), e) {
    int ans = inf;
    for (int z = 0; z * z * z <= e; ++z) {
      int zCubed = z * z * z;
      for (int y = 0; y * y + zCubed <= e; ++y) {
        int ySquared = y * y;
        int x = e - (ySquared + zCubed);
        ans = min(ans, x + y + z);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}