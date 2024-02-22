#include <cstdio>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

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

  unordered_map<int, int> scores;
  priority_queue<data> Q;
  Q.push(data(0, 0));

  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    scores[a] += b;
    Q.push(data(a, scores[a]));
    while (1) {
      data now = Q.top();
      Q.pop();
      cout << now.num << " " << now.score << endl;
      if (now.score == scores[now.num]) {
        break;
      }
    }
  }
  return 0;
}