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
  ios::sync_with_stdio(false); // For faster I/O
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  priority_queue<data> Q;
  data d(0, 0);
  Q.push(d);
  while (m--) {
    int a, b;
    cin >> a >> b;
    S[a] += b;
    d.num = a; d.score = S[a];
    Q.push(d);
    while (1) {
      d = Q.top(); Q.pop();
      if (d.score == S[d.num]) {
        cout << d.num << " " << d.score << "\n";
        break;
      }
    }
  }
  return 0;
}