#include <algorithm>
#include <iostream>
#include <map>
#define fs first
#define sc second
using namespace std;
typedef long long ll;
int n;
pair<ll, int> ab[300010];
ll a[300010];
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> ab[i].fs;
    ab[i].sc = i;
  }
  sort(ab, ab + n);
  int ans = 0;
  ll sum = 0;
  int id = 0, num = 0;
  ll num_plus_one = 1, num_times_fs = 0;
  for (int i = 0; i < n; i++) {
    sum += a[ab[i].sc];
    num++;
    num_plus_one++;
    num_times_fs += ab[i].fs;
    while (id < n && ab[id].fs <= ab[i].fs) {
      sum += a[ab[id].sc];
      num++;
      id++;
    }
    while (id < n) {
      if (sum + a[ab[id].sc] > num_plus_one * ab[i].fs)
        break;
      sum += a[ab[id].sc];
      num++;
      id++;
    }
    if (sum <= num_times_fs)
      ans = max(ans, num);
    sum -= a[ab[i].sc];
    num--;
  }
  cout << ans << endl;
}