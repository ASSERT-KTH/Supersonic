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
    return score < d.score;
  }
};
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  priority_queue<data> Q;
  int maxScore = 0;
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    S[a] += b;
    Q.push(data(a, S[a]));
    maxScore = max(maxScore, S[a]);
  }
  
  while (!Q.empty()) {
    data now = Q.top();
    if (now.score == maxScore) {
      printf("%d %d\n", now.num, now.score);
      break;
    }
    Q.pop();
  }
  
  return 0;
}