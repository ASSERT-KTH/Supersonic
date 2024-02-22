#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll z;
  while (cin >> z && z) {
    ll cubeZ = pow(z, 3); // Compute the cube of 'z' once and store it
    ll ans = 0;
    for (ll x = 1; pow(x, 3) <= cubeZ; x++) {
      for (ll y = 1; y <= z; y++) {
        ll sumCube = pow(x, 3) + pow(y, 3);
        if (sumCube > cubeZ) // If the sum of cubes exceeds 'cubeZ', break the loop
          break;
        ans = max(ans, sumCube);
      }
    }
    cout << cubeZ - ans << endl; // Subtract the maximum sum of cubes from 'cubeZ'
  }
}