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
    if (score != d.score)
      return score < d.score;
    return num > d.num;
  }
};
int main() {
  int n, m, maxScore = 0, maxNum = 0;
  scanf("%d %d", &n, &m);
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    S[a] += b;
    if (S[a] > maxScore) {
      maxScore = S[a];
      maxNum = a;
    }
    printf("%d %d\n", maxNum, maxScore);
  }
  return 0;
}