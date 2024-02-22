#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
  ll z;
  while (cin >> z && z) {
    ll ans = 0;
    ll zCube = z * z * z; // Calculate z^3 once
    ll limit = cbrt(zCube); // Calculate the cube root of z^3 once
    for (ll x = 1; x <= limit; x++) {
      ll xCube = x * x * x; // Calculate x^3 once
      for (ll y = 1; y <= limit; y++) {
        ll yCube = y * y * y; // Calculate y^3 once
        if (xCube + yCube <= zCube)
          ans = max(ans, xCube + yCube);
        else
          break; // Break the loop if the sum exceeds z^3
      }
    }
    cout << zCube - ans << endl;
  }
}