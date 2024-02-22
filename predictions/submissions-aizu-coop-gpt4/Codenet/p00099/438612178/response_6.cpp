#include <cstdio>
#include <iostream>
#include <sstream>
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
inline int readInt() {
  int n = 0;
  char c;
  while ((c = getchar_unlocked()) < '0' || c > '9');
  do {
    n = n * 10 + (c - '0');
  } while ((c = getchar_unlocked()) >= '0' && c <= '9');
  return n;
}
int main() {
  int n = readInt(), m = readInt();
  priority_queue<data> Q;
  Q.push(data(0, 0));
  ostringstream oss;
  while (m--) {
    int a = readInt(), b = readInt();
    S[a] += b;
    Q.push(data(a, S[a]));
    while (1) {
      const data& now = Q.top();
      if (now.score == S[now.num]) {
        oss << now.num << " " << now.score << endl;
        break;
      }
      Q.pop();
    }
  }
  cout << oss.str();
  return 0;
}