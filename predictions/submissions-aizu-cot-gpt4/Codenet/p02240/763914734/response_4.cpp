#include <algorithm>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;
class Relation {
public:
  Relation(int tmp_n, int tmp_m) : n(tmp_n), m(tmp_m), V(tmp_n), group(tmp_n, 0), group_number(1) {}
  void push(int s, int t) {
    V[s].push_back(t);
    V[t].push_back(s);
  }
  void makeGroup() {
    int node;
    queue<int> Q;
    Q.push(0);
    group[0] = 1;
    while (!Q.empty()) {
      int qSize = Q.size();
      for (int i = 0; i < qSize; i++) {
        node = Q.front();
        Q.pop();
        for (auto &k : V[node]) {
          if (group[k] == 0) {
            group[k] = group[node];
            Q.push(k);
          }
        }
      }
      group_number++;
      for (int i = 0; i < n; i++) {
        if (group[i] == 0) {
          group[i] = group_number;
          Q.push(i);
          break;
        }
      }
    }
  }
  bool canAccsess(int s, int t) { return group[s] == group[t]; }

private:
  vector<vector<int>> V;
  vector<int> group;
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
    if (relation.canAccsess(s, t)) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }
  return 0;
}