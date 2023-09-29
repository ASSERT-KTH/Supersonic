#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
ll b_pow(ll x, ll n) {
  return n ? n == 1 ? x : b_pow(x, n >> 1) * b_pow(x, (n >> 1) + (n & 1)) : 1;
}
int main() {
  ll z;
  while (cin >> z && z) {
    ll ans = 0;
    ll max_x = cbrt(z * z * z); // Use cubic root function to compute maximum value of x
    for (ll x = 1; x <= max_x; x++) {
      ll max_y = cbrt(z * z * z - x * x * x); // Compute maximum value of y for each x
      for (ll y = 1; y <= max_y; y++) {
        ll current_sum = x * x * x + y * y * y;
        if (current_sum <= z * z * z) {
          ans = max(ans, current_sum);
        } else {
          break; // If sum is greater than z^3, no need to check further values of y for this x
        }
      }
    }
    cout << z * z * z - ans << endl;
  }
}