#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<pair<ll, int>> p(n);
  vector<pair<ll, int>> b(n);
  vector<bool> use(n, false);

  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> b[i].first;
    p[i].second = i;
    b[i].second = i;
  }

  sort(p.begin(), p.end(), [](const auto& a, const auto& b) {
    return a.first < b.first;
  });

  sort(b.begin(), b.end(), [](const auto& a, const auto& b) {
    return a.first < b.first;
  });

  int ans = 0;
  ll sum = 0;
  int id = 0, num = 0;

  for (int i = 0; i < n; i++) {
    if (!use[b[i].second]) {
      sum += p[b[i].second].first;
      use[b[i].second] = true;
      num++;
    }

    while (id < n && p[id].first <= b[i].first) {
      if (!use[p[id].second]) {
        sum += p[id].first;
        use[p[id].second] = true;
        num++;
      }
      id++;
    }

    while (id < n) {
      if (!use[p[id].second]) {
        if (sum + p[id].first > (num + 1) * b[i].first)
          break;
        sum += p[id].first;
        use[p[id].second] = true;
        num++;
      }
      id++;
    }

    if (sum <= num * b[i].first)
      ans = max(ans, num);

    sum -= p[b[i].second].first;
    num--;
  }

  cout << ans << endl;

  return 0;
}