#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#define fs first
#define sc second
using namespace std;
typedef long long ll;
int n;
pair<ll, int> b[300010];
ll a[300010];
bool use[300010];

int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
  cin >> n;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> p;
  set<pair<ll, int>> bs;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i].fs;
    p.push(make_pair(a[i], i));
    b[i].sc = i;
    bs.insert(b[i]);
    use[i] = false;
  }
  int ans = 0;
  ll sum = 0;
  int num = 0;
  for (auto bi : bs) {
    while (!p.empty() && p.top().fs <= bi.fs) {
      if (!use[p.top().sc]) {
        sum += p.top().fs;
        use[p.top().sc] = true;
        num++;
      }
      p.pop();
    }
    ll next = sum + (p.empty() ? 0 : p.top().fs);
    while (!p.empty() && next <= (num + 1) * bi.fs) {
      sum += p.top().fs;
      use[p.top().sc] = true;
      num++;
      p.pop();
      next = sum + (p.empty() ? 0 : p.top().fs);
    }
    if (sum <= num * bi.fs)
      ans = max(ans, num);
    sum -= a[bi.sc];
    num--;
  }
  cout << ans << endl;
}