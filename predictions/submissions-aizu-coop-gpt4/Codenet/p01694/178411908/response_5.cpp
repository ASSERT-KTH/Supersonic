#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int inf = 1000000000;
const int mod = 1000000007;
const double eps = 1e-9;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int main() {
  int n;
  // Define map for valid string pairs
  map<pair<string, string>, int> valid_pairs = {{{"lu", "ru"}, 1}, {{"ru", "lu"}, 1}, {{"ld", "rd"}, 1}, {{"rd", "ld"}, 1}};
  while (cin >> n, n) {
    int ans = 0;
    string now = "", next;
    rep(i, n) {
      cin >> next;
      // Use map lookup instead of if-else chain
      ans += valid_pairs[{now, next}];
      now = next;
    }
    cout << ans << endl;
  }
  return 0;
}