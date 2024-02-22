#include <cstdio>
#include <iostream>
#include <queue>

int main() {
  int n, m;
  std::scanf("%d %d", &n, &m);
  std::priority_queue<std::pair<int, int>> Q;
  Q.push(std::make_pair(0, 0));
  while (m--) {
    int a, b;
    std::scanf("%d %d", &a, &b);
    // ...
  }
  return 0;
}