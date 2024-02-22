#include <iostream>
#include <queue>
#include <sstream>
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
  cin >> n >> m;
  priority_queue<data> Q;
  Q.push(data(0, 0));
  data now;
  stringstream ss;
  while (m--) {
    int a, b;
    cin >> a >> b;
    S[a] += b;
    now = data(a, S[a]);
    if (now.score == S[now.num]) {
      Q.push(now);
    }
    now = Q.top();
    ss << now.num << " " << now.score << "\n";
    Q.pop();
  }
  cout << ss.str();
  return 0;
}