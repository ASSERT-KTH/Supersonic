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
  cin.tie(0);
  std::ios::sync_with_stdio(0);
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
    ll b_fs = b[i].fs; // avoid redundant computation
    while (id < n && p[id].fs <= b_fs) {
      if (!use[p[id].sc]) {
        sum += p[id].fs;
        use[p[id].sc] = true;
        num++;
      }
      id++;
    }
    ll num_b_fs = num * b_fs; // avoid redundant computation
    while (id < n && sum + p[id].fs <= (num + 1) * b_fs) {
        if (!use[p[id].sc]) {
          sum += p[id].fs;
          use[p[id].sc] = true;
          num++;
        }
        id++;
    }
    if (sum <= num_b_fs)
      ans = max(ans, num);
    sum -= a[b[i].sc];
    num--;
  }
  cout << ans << endl;
}