#include <cstdio>
#include <queue>
using namespace std;

int main() {
  priority_queue<int> pq;
  int n, a, s, max_val;
  while (scanf("%d", &n) != EOF && n) {
    s = max_val = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a);
      s += a;
      pq.push(a);
    }
    while (!pq.empty()) {
      a = pq.top();
      pq.pop();
      max_val = max(max_val, n * s);
      s -= a;
      --n;
    }
    printf("%d\n", max_val);
  }
  return 0;
}