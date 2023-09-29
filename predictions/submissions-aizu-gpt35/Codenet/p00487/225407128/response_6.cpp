#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define fs first
#define sc second
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
  vector<int> id(n);
  iota(id.begin(), id.end(), 0);
  sort(id.begin(), id.end(), [&](int i, int j) { return a[i] < a[j]; });
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i].fs;
    p[i] = make_pair(a[i], i);
    b[i].sc = i;
    use[i] = false;
  }
  sort(p, p + n);
  sort(b, b + n);
  int ans = 0;
  ll sum = 0;
  int num = 0;
  for (int i = 0; i < n; i++) {
    if (!use[b[id[i]].sc]) {
      sum += a[b[id[i]].sc];
      use[b[id[i]].sc] = true;
      num++;
    }
    while (p && p->fs <= b[id[i]].fs) {
      if (!use[p->sc]) {
        sum += p->fs;
        use[p->sc] = true;
        num++;
      }
      ++p;
    }
    while (p != p + n) {
      if (!use[p->sc]) {
        if (sum + p->fs > (num + 1) * b[id[i]].fs)
          break;
        sum += p->fs;
        use[p->sc] = true;
        num++;
      }
      ++p;
    }
    if (sum <= num * b[id[i]].fs)
      ans = max(ans, num);
    sum -= a[b[id[i]].sc];
    num--;
  }
  cout << ans << endl;
}
