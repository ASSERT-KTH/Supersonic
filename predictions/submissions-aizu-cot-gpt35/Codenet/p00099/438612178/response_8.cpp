#include <iostream>
#include <vector>
#include <queue>

const int MAX = 1000001;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int n, m;
  std::cin >> n >> m;

  std::vector<int> S(n + 1, 0);
  std::priority_queue<std::pair<int, int>> Q;

  Q.push({0, 0});

  while (m--) {
    int a, b;
    std::cin >> a >> b;

    S[a] += b;
    Q.push({S[a], a});

    while (Q.top().first != S[Q.top().second]) {
      Q.pop();
    }

    std::cout << Q.top().second << " " << Q.top().first << "\n";
  }

  return 0;
}