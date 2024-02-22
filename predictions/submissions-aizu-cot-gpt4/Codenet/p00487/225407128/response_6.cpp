#include <algorithm>
#include <iostream>
#include <map>
#define fs first
#define sc second
using namespace std;
typedef long long ll;
int n;
pair<ll, int> p[300010], b[300010];
ll a[300010];
bool use[300010];

int main() {
  ([]() { cin.tie(0); std::ios::sync_with_stdio(0); })();  // optimization 1
  cin >> n;
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
  int id = 0, num = 0;
  for (int i = 0; i < n; i++) {
    if (!use[b[i].sc]) {
      sum += a[b[i].sc];
      use[b[i].sc] = true;
      num++;
    }
    while (id < n && p[id].fs <= b[i].fs) {
      if (!use[p[id].sc]) {
        sum += p[id].fs;
        use[p[id].sc] = true;
        num++;
      }
      ++id;  // optimization 3
    }
    ll tmp = (num + 1) * b[i].fs;  // optimization 2
    while (id < n) {
      if (!use[p[id].sc]) {
        if (sum + p[id].fs > tmp)
          break;
        sum += p[id].fs;
        use[p[id].sc] = true;
        num++;
      }
      ++id;  // optimization 3
    }
    if (sum <= num * b[i].fs)
      ans = max(ans, num);
    sum -= a[b[i].sc];
    num--;
  }
  cout << ans << endl;
}