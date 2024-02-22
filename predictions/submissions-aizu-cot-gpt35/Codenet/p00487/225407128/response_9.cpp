#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

const int MAXN = 300010;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  cin >> n;

  ll a[MAXN];
  pair<ll, int> b[MAXN];
  bool use[MAXN];

  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i].first;
    b[i].second = i;
    use[i] = false;
  }

  int ans = 0;
  ll sum = 0;
  int id = 0, num = 0;

  for (int i = 0; i < n; i++) {
    if (!use[b[i].second]) {
      sum += a[b[i].second];
      use[b[i].second] = true;
      num++;
    }

    while (id < n && a[id] <= b[i].first) {
      if (!use[id]) {
        sum += a[id];
        use[id] = true;
        num++;
      }
      id++;
    }

    while (id < n) {
      if (!use[id]) {
        if (sum + a[id] > (num + 1) * b[i].first)
          break;
        sum += a[id];
        use[id] = true;
        num++;
      }
      id++;
    }

    ans = max(ans, num);
    sum -= a[b[i].second];
    num--;
  }

  printf("%d\n", ans);
}