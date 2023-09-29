#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
int n;
pair<ll, int> p[300010], b[300010];
ll a[300010];
bool use[300010];

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  cin >> n;
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
      }
      id++;
    }
    while (id < n && sum + (use[p[id].second] ? 0 : p[id].first) <= (num + !use[p[id].second]) * b[i].first) {
      if (!use[p[id].second]) {
        sum += p[id].first;
        use[p[id].second] = true;
        num++;
      }
      id++;
    }
    ans = max(ans, num);
    sum -= a[b[i].second];
    num--;
    use[b[i].second] = false;
  }
  cout << ans << "\n";
  return 0;
}