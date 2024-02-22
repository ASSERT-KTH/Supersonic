#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll z;
  while (cin >> z && z) {
    ll zCube = z * z * z;  // Calculate z^3 once
    ll ans = 0;

    for (ll x = 1, xCube = x * x * x; xCube <= zCube; ++x, xCube = x * x * x) {
      for (ll y = 1, yCube = y * y * y; yCube + xCube <= zCube; ++y, yCube = y * y * y) {
        ans = max(ans, xCube + yCube);
      }
    }

    cout << zCube - ans << endl;
  }
}