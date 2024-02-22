#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); i++)
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  // Read all numbers from the input
  vector<ll> numbers;
  ll n;
  while (cin >> n && n != 1) {
    numbers.push_back(n);
  }

  // Precompute all factors that are multiples of 7 plus or minus one up to the maximum input number
  ll max_num = *max_element(numbers.begin(), numbers.end());
  vector<ll> lists;
  rep2(i, 2, max_num) {
    if (i % 7 == 1 || i % 7 == 6) {
      lists.push_back(i);
    }
  }

  // For each input number, compute its factors and print them
  vector<ll> ans;
  for (ll num : numbers) {
    ans.clear();
    for (ll p : lists) {
      if (p > num) break;
      if (num % p == 0) {
        ans.push_back(p);
      }
    }
    cout << num << ':';
    rep(i, ans.size()) { cout << " " << ans[i]; }
    cout << endl;
  }

  return 0;
}