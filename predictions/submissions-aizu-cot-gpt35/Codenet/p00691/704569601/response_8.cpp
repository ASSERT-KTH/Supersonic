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
    vector<ll> cubes;
    for (ll i = 1; i * i * i <= z * z * z; i++) {
      cubes.push_back(i * i * i);
    }

    ll x = 1;
    while (x * x * x <= z * z * z) {
      ll y = 1;
      while (y * y * y + x * x * x <= z * z * z) {
        ans = max(ans, x * x * x + y * y * y);
        y++;
      }
      x++;
    }
    
    cout << z * z * z - ans << endl;
  }
}