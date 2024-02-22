#include <algorithm>
#include <queue>
#include <stdio.h>
#include <vector>
#include <unordered_set>
using namespace std;

class Relation {
public:
  Relation(int tmp_n, int tmp_m) : V(tmp_n), group(tmp_n, 0), group_number(1), n(tmp_n), m(tmp_m) {}

  void push(int s, int t) {
    V[s].push_back(t);
    V[t].push_back(s);
  }

  void makeGroup() {
    int node, i;
    queue<int> Q;
    unordered_set<int> ungrouped;
    for (i = 0; i < n; i++) {
      ungrouped.insert(i);
    }
    while (!ungrouped.empty()) {
      Q.push(*ungrouped.begin());
      group[*ungrouped.begin()] = group_number;
      ungrouped.erase(ungrouped.begin());
      while (!Q.empty()) {
        node = Q.front();
        Q.pop();
        for (int k : V[node]) {
          if (group[k] == 0) {
            group[k] = group[node];
            Q.push(k);
            ungrouped.erase(k);
          }
        }
      }
      group_number++;
    }
  }

  bool canAccess(int s, int t) { return group[s] == group[t]; }

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
    if (relation.canAccess(s, t)) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }
  return 0;
}