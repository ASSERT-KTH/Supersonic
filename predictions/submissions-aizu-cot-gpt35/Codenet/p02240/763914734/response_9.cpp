#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Relation {
public:
  Relation(int n, int m) {
    V.resize(n);
    num_of_each.resize(n, 0);
    group.resize(n, 0);
  }

  void push(int s, int t) {
    V[s].push_back(t);
    V[t].push_back(s);
    num_of_each[s]++;
    num_of_each[t]++;
  }

  void makeGroup() {
    int n = V.size();
    std::queue<int> Q;
    Q.push(0);
    group[0] = 1;

    while (!Q.empty()) {
      int node = Q.front();
      Q.pop();

      for (int i = 0; i < num_of_each[node]; i++) {
        int neighbor = V[node][i];
        if (group[neighbor] == 0) {
          group[neighbor] = group[node];
          Q.push(neighbor);
        }
      }

      if (Q.empty()) {
        for (int i = 0; i < n; i++) {
          if (group[i] == 0) {
            group[i] = group.size() + 1;
            Q.push(i);
            break;
          }
        }
      }
    }
  }

  bool canAccess(int s, int t) { return group[s] == group[t]; }

private:
  std::vector<std::vector<int>> V;
  std::vector<int> num_of_each;
  std::vector<int> group;
};

int main() {
  int n, m, s, t, q;
  std::cin >> n >> m;
  Relation relation(n, m);

  for (int i = 0; i < m; i++) {
    std::cin >> s >> t;
    relation.push(s, t);
  }

  relation.makeGroup();

  std::cin >> q;
  for (int i = 0; i < q; i++) {
    std::cin >> s >> t;
    if (relation.canAccess(s, t)) {
      std::cout << "yes\n";
    } else {
      std::cout << "no\n";
    }
  }

  return 0;
}