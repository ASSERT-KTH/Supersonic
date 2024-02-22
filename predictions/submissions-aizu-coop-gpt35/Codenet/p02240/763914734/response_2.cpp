#include <algorithm>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;
class Relation {
public:
  Relation(int tmp_n, int tmp_m) {
    n = tmp_n;
    m = tmp_m;
    V = new int*[n];
    for (int i = 0; i < n; i++) {
      V[i] = new int[n];
      memset(V[i], 0, sizeof(int) * n);
    }
    group = new int[n];
    for (int i = 0; i < n; i++) {
      group[i] = 0;
    }
    group_number = 1;
  }
  void push(int s, int t) {
    V[s][t] = 1;
    V[t][s] = 1;
  }
  void makeGroup() {
    int node, i;
    queue<int> Q;
    Q.push(0);
    group[0] = 1;
    while (!Q.empty()) {
      node = Q.front();
      Q.pop();
      for (int k = 0; k < n; k++) {
        if (V[node][k] && group[k] == 0) {
          group[k] = group[node];
          Q.push(k);
        }
      }
      if (Q.empty()) {
        for (i = 0; i < n; i++) {
          if (group[i] == 0) {
            group[i] = ++group_number;
            Q.push(i);
            break;
          }
        }
      }
    }
  }
  bool canAccess(int s, int t) { return group[s] == group[t]; }

private:
  int **V;
  int *group;
  int group_number;
  int n, m;
};
int main() {
  int n, m, s, t, q;
  scanf("%d %d", &n, &m);
  Relation relation(n, m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &s, &t);
    relation.push(s, t);
  }
  relation.makeGroup();
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d %d", &s, &t);
    if (relation.canAccess(s, t)) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }
  return 0;
}