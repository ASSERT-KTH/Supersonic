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
    ll zCubed = z * z * z;  // Store the cube of z in a variable
    for (ll x = 1; x * x * x <= zCubed; x++)
      for (ll y = 1; y * y * y + x * x * x <= zCubed; y++)
        ans = max(ans, x * x * x + y * y * y);
    cout << zCubed - ans << endl;  // Use the stored value of z cubed
  }
}