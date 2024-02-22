#include <cstdio>
#include <queue>
#include <iostream>

const int MAX = 1000001;
int S[MAX];

struct data {
  int num, score;
  data() {}
  data(int n, int s) : num(n), score(s) {}
  bool operator<(const data &d) const {
    if (score != d.score)
      return score < d.score;
    return num > d.num;
  }
};

int main() {
  int m;
  scanf("%*d %d", &m);

  std::priority_queue<data> Q;
  Q.push(data(0, 0));

  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    S[a] += b;
    Q.push(data(a, S[a]));

    while (1) {
      data& now = Q.top();
      if (now.score == S[now.num]) {
        std::cout << now.num << ' ' << now.score << '\n';
        break;
      }
      Q.pop();
    }
  }

  return 0;
}