#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

typedef int ll;

int main() {
  int n, q;
  cin >> n >> q;

  vector<ll> S(n + 1);

  for (int i = 0; i < q; i++) {
    bool op;
    cin >> op;
    if (op) {
      int k;
      cin >> k;
      int ans = accumulate(S.begin() + k, S.end(), 0);
      cout << ans << '\n';
    } else {
      int s, t, x;
      cin >> s >> t >> x;
      transform(S.begin() + s, S.begin() + t + 1, S.begin() + s, [x](ll val) { return val + x; });
      if (t + 1 <= n)
        S[t + 1] -= x;
    }
  }
}