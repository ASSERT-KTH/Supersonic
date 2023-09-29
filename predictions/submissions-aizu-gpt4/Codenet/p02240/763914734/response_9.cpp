#include <algorithm>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;

class Relation {
public:
  vector<vector<int>> V;
  vector<int> num_of_each, group;
  int group_number, n, m;

  Relation(int tmp_n, int tmp_m) 
    : V(tmp_n), num_of_each(tmp_n, 0), group(tmp_n, 0), n(tmp_n), m(tmp_m), group_number(1) {}

  void push(int s, int t) {
    V[s].push_back(t);
    V[t].push_back(s);
    num_of_each[s]++;
    num_of_each[t]++;
  }

  void makeGroup() {
    int node;
    queue<int> Q;
    Q.push(0);
    group[0] = 1;
    while (!Q.empty() || group_number < n) {
      while (!Q.empty()) {
        node = Q.front();
        Q.pop();
        for (int k = 0; k < num_of_each[node]; k++) {
          if (group[V[node][k]] == 0) {
            group[V[node][k]] = group[node];
            Q.push(V[node][k]);
          }
        }
      }
      for (int i = 0; i < n && Q.empty(); i++) {
        if (group[i] == 0) {
          group[i] = ++group_number;
          Q.push(i);
        }
      }
    }
  }

  bool canAccess(int s, int t) { return group[s] == group[t]; }
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