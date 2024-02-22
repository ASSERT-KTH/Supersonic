#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  vector<vector<int>> edge(n);
  vector<int> cnt(n, 0);
  
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--;
    b--;
    edge[a].push_back(b);
    cnt[b]++;
  }

  vector<int> ans;
  bool flag = false;
  deque<int> next;

  REP(i, n) {
    if (cnt[i] == 0) {
      next.push_back(i);
    }
  }

  while (!next.empty()) {
    int tar = next.back();
    next.pop_back();
    ans.emplace_back(tar + 1);

    if (!next.empty()) {
      flag = true;
    }

    for (int to : edge[tar]) {
      if (--cnt[to] == 0) {
        next.push_back(to);
      }
    }
  }

  for (int i : ans) {
    printf("%d\n", i);
  }

  if (flag) {
    puts("1");
  } else {
    puts("0");
  }

  return 0;
}