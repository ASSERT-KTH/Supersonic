#include <cstdio>
#include <iostream>
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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  scanf("%d %d", &n, &m);
  priority_queue<data, vector<data>, greater<data>> Q;
  Q.push(data(0, 0));
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    S[a] += b;
    Q.push(data(a, S[a]));
    while (1) {
      data now = Q.top();
      if (now.score == S[now.num]) {
        cout << now.num << " " << now.score << "\n";
        break;
      }
      Q.pop();
    }
  }
  return 0;
}