#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll cube_root(ll n) {
  ll x = round(pow(n, 1.0/3.0));
  return (x*x*x == n)? x : x-1;
}
int main() {
  ll z;
  while (cin >> z && z) {
    ll zCube = z*z*z;
    ll x = cube_root(zCube);
    ll ans = max(x*x*x, (x-1)*(x-1)*(x-1));
    cout << zCube - ans << endl;
  }
}