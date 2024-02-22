#include <iostream>
#include <array>
#include <queue>
#include <deque>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

int n, m;
std::array<std::vector<int>, 5000> edge;
std::array<int, 5000> cnt;

int main() {
  std::cin >> n >> m;
  REP(i, m) {
    int a, b;
    std::scanf("%d %d", &a, &b);
    a--;
    b--;
    edge[a].push_back(b);
    cnt[b]++;
  }
  std::deque<int> ans;
  std::queue<int> next;
  REP(i, n) if (cnt[i] == 0) next.push(i);
  REP(i, n) {
    int tar = next.front();
    next.pop();
    ans.push_back(tar + 1);
    REP(j, edge[tar].size()) {
      int to = edge[tar][j];
      if (--cnt[to] == 0)
        next.push(to);
    }
  }
  REP(i, ans.size()) std::printf("%d\n", ans[i]);
  std::puts("0");
  return 0;
}