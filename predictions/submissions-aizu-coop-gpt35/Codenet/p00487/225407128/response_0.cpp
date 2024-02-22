#include <algorithm>
#include <iostream>
#include <vector>
#define fs first
#define sc second
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
  int n;
  cin >> n;

  vector<pair<ll, int>> b(n);
  vector<bool> use(n, false);

  for (int i = 0; i < n; i++) {
    cin >> b[i].fs >> b[i].sc;
    b[i].sc = i;
  }

  sort(b.begin(), b.end());

  int ans = 0;
  ll sum = 0;
  int num = 0;

  for (int i = 0; i < n; i++) {
    sum += b[i].fs;
    num++;
    while (num > 0 && sum > num * b[i].sc) {
      sum -= b[num - 1].fs;
      num--;
    }
    ans = max(ans, num);
  }

  cout << ans << endl;
}