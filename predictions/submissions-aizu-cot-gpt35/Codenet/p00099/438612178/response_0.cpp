#include <iostream>
#include <queue>

constexpr int MAX = 1000001;

struct data {
  int num, score;
  data() {}
  data(int n, int s) : num(n), score(s) {}
  bool operator<(const data& d) const {
    return score < d.score;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  std::vector<int> S(MAX);
  std::priority_queue<data> Q;
  Q.push({0, 0});

  while (m--) {
    int a, b;
    std::cin >> a >> b;

    S[a] += b;
    Q.push({a, S[a]});

    while (true) {
      const data& now = Q.top();
      if (now.score == S[now.num]) {
        break;
      }
      Q.pop();
    }
  }

  return 0;
}