#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;
typedef long long ll;
int n;
pair<ll, int> p[300010], b[300010];
ll a[300010];
unordered_set<int> used;
int main() {
  ios::sync_with_stdio(0);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld%d", &a[i], &b[i].first);
    p[i] = make_pair(a[i], i);
    b[i].second = i;
  }
  sort(p, p + n);
  sort(b, b + n);
  int ans = 0;
  ll sum = 0;
  int id = 0, num = 0;
  for (int i = 0; i < n; i++) {
    if (used.find(b[i].second) == used.end()) {
      sum += a[b[i].second];
      used.insert(b[i].second);
      num++;
    }
    while (id < n && p[id].first <= b[i].first) {
      if (used.find(p[id].second) == used.end()) {
        sum += p[id].first;
        used.insert(p[id].second);
        num++;
      }
      id++;
    }
    ll newSum = sum;
    int newNum = num;
    while (id < n && newSum + p[id].first <= (newNum + 1) * b[i].first) {
      if (used.find(p[id].second) == used.end()) {
        newSum += p[id].first;
        used.insert(p[id].second);
        newNum++;
      }
      id++;
    }
    if (newSum <= num * b[i].first)
      ans = max(ans, num);
    sum -= a[b[i].second];
    num--;
  }
  printf("%d\n", ans);
}