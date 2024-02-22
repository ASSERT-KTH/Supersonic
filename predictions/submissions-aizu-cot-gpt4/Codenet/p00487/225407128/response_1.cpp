#include <algorithm>
#include <iostream>
#define fs first
#define sc second
using namespace std;
typedef long long ll;
int n;
pair<ll, int> p[300010];
ll a[300010];
bool use[300010];
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> p[i].fs;
    p[i].sc = i;
    use[i] = false;
  }
  sort(p, p + n);
  int ans = 0;
  ll sum = 0;
  int id = 0;
  for (int i = 0; i < n; i++) {
    if (!use[p[i].sc]) {
      sum += a[p[i].sc];
      use[p[i].sc] = true;
    }
    while (id < n && p[id].fs <= p[i].fs) {
      if (!use[p[id].sc]) {
        sum += p[id].fs;
        use[p[id].sc] = true;
      }
      id++;
    }
    while (id < n) {
      if (!use[p[id].sc]) {
        if (sum + p[id].fs > (count(use, use + n, true) + 1) * p[i].fs)
          break;
        sum += p[id].fs;
        use[p[id].sc] = true;
      }
      id++;
    }
    if (sum <= count(use, use + n, true) * p[i].fs)
      ans = max(ans, count(use, use + n, true));
    sum -= a[p[i].sc];
  }
  cout << ans << endl;
}