#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf = 1000000000;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll e;
  while (cin >> e, e) {
    ll ans = inf;
    for (ll z = 0; z * z * z <= e; ++z) {
      ll y = e - z * z * z;
      ll y_sqrt = sqrt(y);
      ans = min(ans, y_sqrt + z);
    }
    cout << ans << "\n";
  }
  return 0;
}