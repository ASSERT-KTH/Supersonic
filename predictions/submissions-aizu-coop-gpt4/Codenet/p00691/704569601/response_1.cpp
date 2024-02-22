#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll z;
  while (cin >> z && z) {
    ll ans = 0;
    ll z_cubed = z * z * z;  
    ll limit = cbrt(z_cubed);  

    for (ll x = 1; x <= limit; x++) {
      ll x_cubed = x * x * x;

      for (ll y = 1; y <= limit; y++) {
        ll y_cubed = y * y * y;

        if (x_cubed + y_cubed <= z_cubed)
          ans = max(ans, x_cubed + y_cubed);
        else
          break;  
      }
    }
    cout << z_cubed - ans << endl;
  }
}