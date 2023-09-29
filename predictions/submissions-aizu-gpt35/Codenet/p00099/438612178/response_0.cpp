#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  scanf("%d %d", &n, &m);
  vector<data> Q(m + 1);
  int tail = 0;
  Q[tail++] = data(0, 0);
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    S[a] += b;
    Q[tail++] = data(a, S[a]);
    while (1) {
      data now = Q[tail - 1];
      if (now.score == S[now.num]) {
        cout << now.num << " " << now.score << endl;
        break;
      }
      tail--;
    }
  }
  return 0;
}