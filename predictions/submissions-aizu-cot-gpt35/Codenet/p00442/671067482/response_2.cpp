#include <iostream>
#include <vector>

typedef std::pair<int, int> pii;

void FOR(int& i, int a, int b) {
  for (i = a; i < b; i++);
}

void REP(int& i, int n) {
  FOR(i, 0, n);
}

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> edge(n);
  std::vector<int> cnt(n);

  REP(i, m) {
    int a, b;
    std::cin >> a >> b;
    a--;
    b--;
    edge[a].push_back(b);
    cnt[b]++;
  }

  std::vector<int> ans;
  bool flag = false;
  std::vector<int> next;
  next.reserve(n);

  REP(i, n) {
    int tar = next.back();
    ans.push_back(tar + 1);
    next.pop_back();

    if (!next.empty())
      flag = true;

    REP(j, edge[tar].size()) {
      int to = edge[tar][j];
      if (--cnt[to] == 0)
        next.push_back(to);
    }
  }

  REP(i, ans.size()) {
    std::cout << ans[i] << "\n";
  }

  if (flag)
    std::cout << "1\n";
  else
    std::cout << "0\n";

  return 0;
}