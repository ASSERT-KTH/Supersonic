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
  vector<ll> cubes;
  for (ll i = 1; i <= 10000; i++) {
    cubes.push_back(i * i * i);
  }
  while (cin >> z && z) {
    ll ans = 0;
    for (ll i = 0; i < cubes.size(); i++) {
      if (cubes[i] > z * z * z) {
        break;
      }
      for (ll j = i; j < cubes.size(); j++) {
        ll sum = cubes[i] + cubes[j];
        if (sum > z * z * z) {
          break;
        }
        ans = max(ans, sum);
      }
    }
    cout << z * z * z - ans << endl;
  }
}