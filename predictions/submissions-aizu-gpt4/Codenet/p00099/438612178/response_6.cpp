#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 1000001;
int S[MAX];
struct data {
  int num, score;
  data() {}
  data(int n, int s) : num(n), score(s) {}
  bool operator<(const data &d) const {
    return score != d.score ? score < d.score : num > d.num;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  scanf("%d %d", &n, &m);
  priority_queue<data> Q;
  Q.push(data(0, 0));
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    S[a] += b;
    Q.push(data(a, S[a]));
    while (Q.top().score != S[Q.top().num]) Q.pop();
    printf("%d %d\n", Q.top().num, Q.top().score);
  }
  return 0;
}