#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ll z;
  while (cin >> z && z) {
    ll ans = 0;
    ll zCube = z * z * z; // store the cube of z
    for (ll x = 1; x * x * x <= zCube; x++) {
      ll xCube = x * x * x; // store the cube of x
      ll y = cbrt(zCube - xCube); // calculate y from x
      ll yCube = y * y * y; // store the cube of y
      ans = max(ans, xCube + yCube);
    }
    cout << zCube - ans << endl;
  }
}