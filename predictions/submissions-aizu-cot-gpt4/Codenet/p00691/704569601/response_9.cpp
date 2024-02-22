#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll z;
  while (cin >> z && z) {
    ll ans = 0;
    ll z_cubed = z * z * z;
    for (ll x = 1; x * x * x <= z_cubed; x++){
      ll x_cubed = x * x * x;
      for (ll y = 1; y * y * y + x_cubed <= z_cubed; y++){
        ll y_cubed = y * y * y;
        ans = max(ans, x_cubed + y_cubed);
      }
    }
    cout << z_cubed - ans << endl;
  }
}