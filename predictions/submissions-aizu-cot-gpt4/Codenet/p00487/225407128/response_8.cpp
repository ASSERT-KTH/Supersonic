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

int main() {
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
    if (p[id].sc != b[i].sc) {
      sum += a[b[i].sc];
      num++;
    }
    while (id < n && (p[id].fs <= b[i].fs || (sum + p[id].fs <= (num + 1) * b[i].fs))) {
      if (p[id].sc != b[i].sc) {
        sum += p[id].fs;
        num++;
      }
      id++;
    }
    ans = max(ans, num);
    sum -= a[b[i].sc];
    num--;
  }
  cout << ans << endl;
}