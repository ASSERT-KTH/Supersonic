#include <cstdio>
#include <queue>
#include <iostream>

const int MAX = 1000001;
int S[MAX];

struct data {
  int num, score;
  data() {}
  data(int n, int s) : num(n), score(s) {}
};

struct Compare {
  bool operator()(const data& d1, const data& d2) {
    if (d1.score != d2.score)
      return d1.score < d2.score;
    return d1.num > d2.num;
  }
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  std::priority_queue<data, std::vector<data>, Compare> Q;
  Q.push(data(0, 0));

  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    S[a] += b;
    Q.push(data(a, S[a]));
    while (!Q.empty()) {
      data now = Q.top();
      if (now.score == S[now.num]) {
        std::cout << now.num << " " << now.score << std::endl;
        break;
      }
      Q.pop();
    }
  }
  return 0;
}