#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll z;
  while (cin >> z && z) {
    ll z_cubed = z * z * z;
    ll ans = 0;

    for (ll x = 1; ; x++) {
      ll x_cubed = x * x * x;
      if (x_cubed >= z_cubed) break;

      for (ll y = 1; ; y++) {
        ll sum = x_cubed + y * y * y;
        if (sum > z_cubed) break;
        ans = max(ans, sum);
      }
    }

    cout << z_cubed - ans << endl;
  }
}