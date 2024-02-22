#include <algorithm>
#include <iostream>
#include <unordered_set>

#define fs first
#define sc second

using namespace std;
typedef long long ll;

int n;
pair<ll, int> p[300010], b[300010];
ll a[300010];
unordered_set<int> used;

int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
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

  for (int i = 0; i < n; i++) {
    if (used.find(b[i].sc) == used.end()) {
      sum += a[b[i].sc];
      used.insert(b[i].sc);
      num++;
    }
    while (id < n && (p[id].fs <= b[i].fs || 
                      (used.find(p[id].sc) == used.end() && sum + p[id].fs <= (num + 1) * b[i].fs))) {
      if (used.find(p[id].sc) == used.end()) {
        sum += p[id].fs;
        used.insert(p[id].sc);
        num++;
      }
      id++;
    }
    if (sum <= num * b[i].fs)
      ans = max(ans, num);
    sum -= a[b[i].sc];
    num--;
  }
  cout << ans << endl;
}