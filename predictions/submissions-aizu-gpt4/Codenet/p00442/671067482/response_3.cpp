#include <cstdio>
#include <vector>
#define REP(i, n) for (int i = 0; i < (n); i++)
typedef std::pair<int, int> pii;
int n, m;
std::vector<int> edge[5000];
int cnt[5000];
int main() {
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    edge[a].push_back(b);
    cnt[b]++;
  }
  std::vector<int> ans, next;
  REP(i, n) if (cnt[i] == 0) next.push_back(i);
  REP(i, n) {
    int tar = next.back();
    next.pop_back();
    ans.push_back(tar + 1);
    REP(j, edge[tar].size()) {
      int to = edge[tar][j];
      if (--cnt[to] == 0)
        next.push_back(to);
    }
  }
  REP(i, ans.size()) printf("%d\n", ans[i]);
  printf("%d\n", !next.empty());
  return 0;
}