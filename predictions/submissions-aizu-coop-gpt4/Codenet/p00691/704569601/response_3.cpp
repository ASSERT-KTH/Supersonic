#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

int main() {
  ll z;
  while (cin >> z && z) {
    ll ans = 0;
    ll z_cubed = z * z * z; // cube of z calculated once and stored in variable
    ll x, y;
    for (x = 1; x * x * x <= z_cubed; x++) {
      ll x_cubed = x * x * x; // cube of x calculated once and stored in variable
      for (y = x; y * y * y + x_cubed <= z_cubed; y++) { // y loop starts from x
        ll y_cubed = y * y * y; // cube of y calculated once and stored in variable
        ans = max(ans, x_cubed + y_cubed);
      }
    }
    cout << z_cubed - ans << endl;
  }
}