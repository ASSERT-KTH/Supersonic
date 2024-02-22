#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
int n;
pair<ll, int> p[300010], b[300010];
ll a[300010];
bool use[300010];
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
  cin >> n;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i].first;
    p[i] = make_pair(a[i], i);
    b[i].second = i;
    use[i] = false;
  }
  sort(p, p + n);
  sort(b, b + n);
  int ans = 0;
  ll sum = 0;
  int id = 0, num = 0;
  for (int i = 0; i < n; i++) {
    if (!use[b[i].second]) {
      sum += a[b[i].second];
      use[b[i].second] = true;
      num++;
    }
    while (id < n && p[id].first <= b[i].first) {
      if (!use[p[id].second]) {
        sum += p[id].first;
        use[p[id].second] = true;
        num++;
        pq.push(p[id].first);
      }
      id++;
    }
    while (!pq.empty() && sum + pq.top() > (num + 1) * b[i].first) {
      sum -= pq.top();
      pq.pop();
      num--;
    }
    if (sum <= num * b[i].first)
      ans = max(ans, num);
    sum -= a[b[i].second];
    num--;
  }
  cout << ans << endl;
}