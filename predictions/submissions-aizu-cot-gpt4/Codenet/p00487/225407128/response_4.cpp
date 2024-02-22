#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<ll, int>> p(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> b[i].first;
    p[i].second = i;
    b[i].second = i;
  }
  sort(p.begin(), p.end());
  sort(b.begin(), b.end());
  int ans = 0;
  ll sum = 0;
  int id = 0, num = 0;
  for (int i = 0; i < n; i++) {
    if (p[b[i].second].first == b[i].first) {
      sum += p[b[i].second].first;
      num++;
    }
    while (id < n && p[id].first <= b[i].first) {
      sum += p[id].first;
      num++;
      id++;
    }
    while (id < n && sum + p[id].first <= (num + 1) * b[i].first) {
      sum += p[id].first;
      num++;
      id++;
    }
    if (sum <= num * b[i].first)
      ans = max(ans, num);
    sum -= p[b[i].second].first;
    num--;
  }
  cout << ans << endl;
}