#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
class Relation {
public:
  Relation(int tmp_n, int tmp_m) : n(tmp_n), m(tmp_m), group_number(1), V(tmp_n), group(tmp_n, 0) {}

  void push(int s, int t) {
    V[s].push_back(t);
    V[t].push_back(s);
  }

  void makeGroup() {
    int node, i;
    queue<int> Q;
    Q.push(0);
    group[0] = 1;
    while (!Q.empty() || group_number < n) {
      while (!Q.empty()) {
        node = Q.front();
        Q.pop();
        for (auto k : V[node]) {
          if (group[k] == 0) {
            group[k] = group[node];
            Q.push(k);
          }
        }
      }
      group_number++;
      for (i = 0; i < n; i++) {
        if (group[i] == 0) {
          group[i] = group_number;
          Q.push(i);
          break;
        }
      }
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
  cin >> n >> m;
  Relation relation(n, m);
  for (int i = 0; i < m; i++) {
    cin >> s >> t;
    relation.push(s, t);
  }
  relation.makeGroup();
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> s >> t;
    if (relation.canAccess(s, t)) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
  return 0;
}