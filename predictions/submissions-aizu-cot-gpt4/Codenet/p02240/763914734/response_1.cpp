#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;

class Relation {
public:
  Relation(int tmp_n, int tmp_m) : V(tmp_n), group(tmp_n, 0), n(tmp_n), m(tmp_m) {}

  void push(int s, int t) {
    V[s].push_back(t);
    V[t].push_back(s);
  }

  void makeGroup() {
    int group_number = 1;
    for (int i = 0; i < n; i++) {
      if (group[i] == 0) {
        queue<int> Q;
        Q.push(i);
        group[i] = group_number;
        while (!Q.empty()) {
          int node = Q.front();
          Q.pop();
          for (const auto& neighbour : V[node]) {
            if (group[neighbour] == 0) {
              group[neighbour] = group_number;
              Q.push(neighbour);
            }
          }
        }
        group_number++;
      }
    }
  }

  bool canAccess(int s, int t) { return group[s] == group[t]; }

private:
  vector<vector<int>> V;
  vector<int> group;
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