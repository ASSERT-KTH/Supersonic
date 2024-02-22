#include <algorithm>
#include <iostream>
#define fs first
#define sc second
using namespace std;
typedef long long ll;
int n;
pair<ll, int> p[300010];
ll a[300010], b[300010];
bool use[300010];
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    p[i] = make_pair(a[i], i);
    use[i] = false;
  }
  sort(p, p + n);
  sort(b, b + n);
  int ans = 0;
  ll sum = 0;
  int id = 0, num = 0;
  for (int i = 0; i < n; i++) {
    if (!use[b[i]]) {
      sum += a[b[i]];
      use[b[i]] = true;
      num++;
    }
    while (id < n) {
      bool condition = !use[p[id].sc];
      if (condition && p[id].fs <= b[i]) {
        sum += p[id].fs;
        use[p[id].sc] = true;
        num++;
      } else if (condition && sum + p[id].fs <= (num + 1) * b[i]) {
        sum += p[id].fs;
        use[p[id].sc] = true;
        num++;
      } else {
        break;
      }
      id++;
    }
    if (sum <= num * b[i])
      ans = max(ans, num);
    sum -= a[b[i]];
    num--;
  }
  cout << ans << endl;
}