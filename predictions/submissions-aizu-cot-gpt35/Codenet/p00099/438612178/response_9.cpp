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
  int maxScore = 0; // new variable to keep track of the maximum score
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    S[a] += b;
    Q.push(data(a, S[a]));
    if (S[a] > maxScore) { // update the maximum score if necessary
      maxScore = S[a];
      cout << a << " " << maxScore << endl; // print the number and the maximum score
    }
  }
  return 0;
}