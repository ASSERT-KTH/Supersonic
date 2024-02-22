#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;

class Relation {
public:
  Relation(int tmp_n) {
    n = tmp_n;
    V.resize(n);
    group.resize(n, 0);
    group_number = 1;
  }
  void push(int s, int t) {
    V[s].push_back(t);
    V[t].push_back(s);
  }
  void makeGroup() {
    int node, i;
    queue<int> Q;
    Q.push(0);
    group[0] = 1;
    while (true) {
      while (!Q.empty()) {
        node = Q.front();
        Q.pop();
        for (int k = 0; k < V[node].size(); k++) {
          if (group[V[node][k]] == 0) {
            group[V[node][k]] = group[node];
            Q.push(V[node][k]);
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
      if (i == n)
        break;
    }
  }
  bool canAccsess(int s, int t) { return group[s] == group[t]; }

private:
  vector<vector<int>> V;
  vector<int> group;
  int group_number;
  int n;
};

int main() {
  int n, m, s, t, q;
  cin >> n >> m;
  Relation relation(n);
  for (int i = 0; i < m; i++) {
    cin >> s >> t;
    relation.push(s, t);
  }
  relation.makeGroup();
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> s >> t;
    if (relation.canAccsess(s, t)) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
  return 0;
}