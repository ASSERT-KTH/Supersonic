#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  scanf("%d %d", &n, &m);
  priority_queue<data> Q;
  Q.push(data(0, 0));
  vector<pair<int, int>> input(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &input[i].first, &input[i].second);
  }
  for (int i = 0; i < m; ++i) {
    S[input[i].first] += input[i].second;
    Q.push(data(input[i].first, S[input[i].first]));
    while (1) {
      data now = Q.top();
      if (now.score == S[now.num]) {
        printf("%d %d\n", now.num, now.score);
        break;
      }
      Q.pop();
    }
  }
  return 0;
}