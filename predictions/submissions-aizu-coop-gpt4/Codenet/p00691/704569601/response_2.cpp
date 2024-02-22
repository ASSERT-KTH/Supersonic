#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll z;
  while (cin >> z && z) {
    ll ans = 0;
    ll cube_z = z * z * z;
    for (ll x = 1; x * x * x <= cube_z; x++)
      for (ll y = x; y * y * y + x * x * x <= cube_z; y++)
        ans = max(ans, x * x * x + y * y * y);
    cout << cube_z - ans << endl;
  }
}