#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  // Pre-calculate the list of required numbers
  vector<ll> lists;
  lists.reserve(60000);
  rep2(i, 2, 300000 + 1) {
    if (i % 7 == 1 || i % 7 == 6) {
      lists.pb(i);
    }
  }

  // Read the input number and calculate the factors
  ll n;
  cin >> n;
  vector<ll> ans;
  ans.reserve(60000);
  for (auto p : lists) {
    if (n % p == 0) {
      ans.pb(p);
    }
  }

  // Prepare the output string
  string output = to_string(n) + ':';
  for (auto i : ans) {
    output += " " + to_string(i);
  }

  // Print out the result
  cout << output << endl;
  return 0;
}