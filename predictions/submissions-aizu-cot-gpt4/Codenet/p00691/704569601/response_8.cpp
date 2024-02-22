#include <iostream>
using namespace std;
typedef long long ll;

ll cube(ll x) {
  return x * x * x;
}

int main() {
  ll z;
  while (cin >> z && z) {
    ll ans = 0;
    for (ll x = 1; cube(x) <= cube(z); x++)
      for (ll y = 1; y <= z; y++){
        ll temp = cube(x) + cube(y);
        if(temp > cube(z))
            break;
        ans = max(ans, temp);
      }
    cout << cube(z) - ans << endl;
  }
}