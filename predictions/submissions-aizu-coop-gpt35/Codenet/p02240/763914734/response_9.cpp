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
    V.resize(n); // Use vector instead of dynamic allocation
    num_of_each.resize(n, 0); // Initialize with 0
    group.resize(n, 0); // Initialize with 0
  }

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
    while (!Q.empty()) {
      node = Q.front();
      Q.pop();
      if (num_of_each[node] > 0) {
        for (int k = 0; k < num_of_each[node]; k++) {
          if (group[V[node][k]] == 0) {
            group[V[node][k]] = group[node];
            Q.push(V[node][k]);
          }
        }
      }
    }
  }

  bool canAccsess(int s, int t) { return group[s] == group[t]; }

private:
  vector<vector<int>> V;
  vector<int> num_of_each;
  vector<int> group;
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