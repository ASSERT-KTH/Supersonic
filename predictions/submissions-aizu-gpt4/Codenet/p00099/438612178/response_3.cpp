#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 1000001;
int S[MAX];
struct data {
  int num, score;
  data(int n, int s) : num(n), score(s) {}
  bool operator<(const data &d) const {
    if (score != d.score)
      return score < d.score;
    return num > d.num;
  }
};
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  priority_queue<data> Q;
  vector<data> v;
  v.reserve(m);
  Q.push(data(0, 0));
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    S[a] += b;
    v.emplace_back(a, S[a]);
  }
  for (const auto &d : v) {
    Q.push(d);
    while (Q.top().score != S[Q.top().num]) {
      Q.pop();
    }
    printf("%d %d\n", Q.top().num, Q.top().score);
  }
  return 0;
}