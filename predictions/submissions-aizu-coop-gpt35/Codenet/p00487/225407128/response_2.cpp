#include <algorithm>
#include <iostream>
#include <unordered_map>
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

  vector<ll> a(n);
  vector<pair<ll, int>> p(n);
  vector<pair<ll, int>> b(n);
  unordered_map<int, bool> use;

  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i].fs;
    p[i] = make_pair(a[i], i);
    b[i].sc = i;
    use[i] = false;
  }

  stable_sort(p.begin(), p.end());
  stable_sort(b.begin(), b.end());

  int ans = 0;
  ll sum = 0;
  int id = 0, num = 0;

  for (int i = 0; i < n; i++) {
    if (!use[b[i].sc] && num < n) {
      sum += a[b[i].sc];
      use[b[i].sc] = true;
      num++;
    }

    for (; id < n; id++) {
      if (!use[p[id].sc] && sum + p[id].fs <= (num + 1) * b[i].fs) {
        sum += p[id].fs;
        use[p[id].sc] = true;
        num++;
      } else {
        break;
      }
    }

    if (sum <= num * b[i].fs) {
      ans = max(ans, num);
    }

    sum -= a[b[i].sc];
    num--;
  }

  cout << ans << endl;
}