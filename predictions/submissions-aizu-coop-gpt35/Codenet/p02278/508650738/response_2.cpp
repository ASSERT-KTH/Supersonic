#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_SIZE 1000000

struct QuickFind {
  int r[MAX_SIZE], p[MAX_SIZE];
  vector<int> v[MAX_SIZE];

  QuickFind() {}
  QuickFind(int size) { init(size); }

  void init(int size) {
    for (int i = 0; i < size; i++) {
      r[i] = 1;
      p[i] = i;
      v[i].clear();
      v[i].push_back(i);
    }
  }

  bool same(int x, int y) {
    return p[x] == p[y];
  }

  void unite(int x, int y) {
    x = p[x];
    y = p[y];
    if (x == y)
      return;
    if (r[x] < r[y])
      swap(x, y);
    r[x] += r[y];
    for (int i = 0; i < (int)v[y].size(); i++) {
      p[v[y][i]] = x;
      v[x].push_back(v[y][i]);
    }
    v[y].clear();
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  QuickFind qf(n);
  for (int i = 0; i < n; i++)
    qf.unite(i, i);
  int ans = 0;
  int sum = 0;
  int min_val = a[0];
  for (int i = 0; i < n; i++) {
    int k = qf.v[i].size();
    if (qf.p[i] != i || k == 1)
      continue;
    sum += a[i];
    min_val = min(min_val, a[i]);
    ans += sum + min_val * (k - 2);
  }
  cout << ans << endl;
  return 0;
}