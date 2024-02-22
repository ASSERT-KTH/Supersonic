#include <cstdio>
#include <iostream>
#include <vector>

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> edge(n);
  std::vector<int> cnt(n);

  REP(i, m) {
    int a, b;
    std::scanf("%d %d", &a, &b);
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
    if (cnt[i] == 0) {
      next.push_back(i);
    }
  }

  REP(i, n) {
    int tar = next.back();
    next.pop_back();

    ans.push_back(tar + 1);

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
    std::printf("%d\n", i);
  }

  if (flag) {
    std::cout << "1\n";
  } else {
    std::cout << "0\n";
  }

  return 0;
}