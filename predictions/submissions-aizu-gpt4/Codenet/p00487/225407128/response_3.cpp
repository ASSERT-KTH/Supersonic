#include <algorithm>
#include <iostream>
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
  std::ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i].fs;
    p[i] = make_pair(a[i], i);
    b[i].sc = i;
  }
  sort(p, p + n);
  sort(b, b + n);
  int ans = 0;
  ll sum = 0;
  int id = 0, num = 0;
  vector<int> usedIndex;
  for (int i = 0; i < n; i++) {
    if (!use[b[i].sc]) {
      sum += a[b[i].sc];
      use[b[i].sc] = true;
      num++;
      usedIndex.push_back(b[i].sc);
    }
    while (id < n && p[id].fs <= b[i].fs) {
      if (!use[p[id].sc]) {
        sum += p[id].fs;
        use[p[id].sc] = true;
        num++;
        usedIndex.push_back(p[id].sc);
      }
      id++;
    }
    while (id < n) {
      if (!use[p[id].sc]) {
        if (sum + p[id].fs > (num + 1) * b[i].fs)
          break;
        sum += p[id].fs;
        use[p[id].sc] = true;
        num++;
        usedIndex.push_back(p[id].sc);
      }
      id++;
    }
    if (sum <= num * b[i].fs)
      ans = max(ans, num);
    for (const auto &idx : usedIndex) {
      sum -= a[idx];
      use[idx] = false;
      num--;
    }
    usedIndex.clear();
  }
  cout << ans << endl;
}