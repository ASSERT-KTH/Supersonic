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
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  priority_queue<data> Q;
  Q.push(data(0, 0));
  while (m--) {
    int a, b;
    cin >> a >> b;
    S[a] += b;
    Q.push(data(a, S[a]));
    data now = Q.top();
    while (1) {
      if (now.score == S[now.num]) {
        cout << now.num << " " << now.score << "\n";
        break;
      }
      Q.pop();
      now = Q.top();
    }
  }
  return 0;
}