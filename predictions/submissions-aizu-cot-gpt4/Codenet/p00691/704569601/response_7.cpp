#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll z;
  while (cin >> z && z) {
    ll z_cubed = z * z * z;
    ll ans = 0;
    for (ll x = 1; x * x * x <= z_cubed; x++) {
      for (ll y = min(z, x); y > 0 && y * y * y + x * x * x <= z_cubed; y--) {
        ans = max(ans, x * x * x + y * y * y);
      }
    }
    cout << z_cubed - ans << endl;
  }
}