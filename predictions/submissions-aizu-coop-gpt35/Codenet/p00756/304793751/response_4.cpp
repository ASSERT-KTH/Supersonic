#include <bits/stdc++.h>
using namespace std;

struct Circle {
  int x, y, r, c;
};

int n;
vector<Circle> circles;
vector<bool> memo;
vector<int> results;

bool ok(int a, int bit) {
  int dist = (circles[a].x - circles[bit].x) * (circles[a].x - circles[bit].x) +
              (circles[a].y - circles[bit].y) * (circles[a].y - circles[bit].y);
  for (int i = 0; i < a; i++) {
    int sum = (circles[i].r + circles[a].r) * (circles[i].r + circles[a].r);
    if (dist < sum)
      return false;
  }
  return true;
}

int dfs(int bit) {
  memo[bit] = true;
  int ret = n;
  for (int i = 0; i < n; i++)
    if ((bit >> i) & 1)
      ret--;
  for (int i = 0; i < n; i++) {
    if (((bit >> i) & 1) == 0 || ok(i, bit) == false)
      continue;
    for (int j = i + 1; j < n; j++) {
      if (((bit >> j) & 1) == 0 || circles[i].c != circles[j].c)
        continue;
      int to_bit = (bit ^ (1 << i)) ^ (1 << j);
      if (ok(j, bit) && !memo[to_bit]) {
        ret = max(ret, dfs(to_bit));
      }
    }
  }
  return ret;
}

void solve() {
  memo.resize(1 << n, false);
  results.push_back(dfs((1 << n) - 1));
}

bool input() {
  cin >> n;
  if (!n)
    return false;
  circles.resize(n);
  for (int i = 0; i < n; i++)
    cin >> circles[i].x >> circles[i].y >> circles[i].r >> circles[i].c;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  while (input())
    solve();
  for (int result : results)
    cout << result << endl;
  return 0;
}