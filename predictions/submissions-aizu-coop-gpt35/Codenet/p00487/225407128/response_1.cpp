#include <algorithm>
#include <iostream>
#include <map>
#define fs first
#define sc second
using namespace std;
typedef long long ll;
int n;
pair<ll, int> p[300010];
pair<ll, int> b_use[300010]; // Combined array for b[] and use[]
ll a[300010];
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b_use[i].fs;
    p[i] = make_pair(a[i], i);
    b_use[i].sc = i;
  }
  sort(p, p + n);
  sort(b_use, b_use + n);
  int ans = 0;
  ll sum = 0;
  int id = 0, num = 0;
  for (int i = 0; i < n; i++) {
    if (!b_use[i].sc) {
      sum += a[b_use[i].sc];
      b_use[i].sc = true;
      num++;
    }
    while (id < n && p[id].fs <= b_use[i].fs) {
      if (!b_use[p[id].sc]) {
        sum += p[id].fs;
        b_use[p[id].sc] = true;
        num++;
      }
      id++;
    }
    while (id < n) {
      if (!b_use[p[id].sc]) {
        if (sum + p[id].fs > (num + 1) * b_use[i].fs)
          break;
        sum += p[id].fs;
        b_use[p[id].sc] = true;
        num++;
      }
      id++;
    }
    if (sum <= num * b_use[i].fs)
      ans = max(ans, num);
    sum -= a[b_use[i].sc];
    num--;
  }
  cout << ans << endl;
}