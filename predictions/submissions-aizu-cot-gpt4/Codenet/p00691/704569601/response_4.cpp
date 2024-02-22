#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll z;
  while (cin >> z && z) {
    ll ans = 0;
    ll zCube = z * z * z; // calculate z^3 once
    for (ll x = 1, xCube = 1; xCube <= zCube; x++, xCube = x * x * x) {
      for (ll y = 1, yCube = 1; yCube + xCube <= zCube; y++, yCube = y * y * y) {
        ans = max(ans, xCube + yCube); // Use the calculated value of x^3 and y^3
      }
    }
    cout << zCube - ans << endl; // Use the calculated value of z^3
  }
}