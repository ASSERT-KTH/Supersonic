#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
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
  int n, m;
  scanf("%d %d", &n, &m);
  priority_queue<data> Q;
  Q.push(data(0, 0));
  int max_score = 0;
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    S[a] += b;
    if (S[a] > max_score) {
      max_score = S[a];
      cout << a << " " << max_score << endl;
    }
  }
  return 0;
}
