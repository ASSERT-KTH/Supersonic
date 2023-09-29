#include <iostream>
#include <vector>
#include <queue>
using namespace std;

constexpr int MAXN = 5000;
vector<int> edge[MAXN];
int cnt[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for(int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    edge[a].push_back(b);
    ++cnt[b];
  }

  queue<int> next;
  for(int i = 0; i < n; ++i) {
    if (cnt[i] == 0) next.push(i);
  }

  vector<int> ans(n);
  bool flag = false;
  for(int i = 0; i < n; ++i) {
    if (next.empty()) {
      flag = true;
      break;
    }
    int tar = next.front();
    next.pop();
    ans[i] = tar + 1;

    for(auto to : edge[tar]) {
      if (--cnt[to] == 0) next.push(to);
    }
  }

  for(auto i : ans) cout << i << '\n';
  cout << (flag ? "1\n" : "0\n");
  return 0;
}