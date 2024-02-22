#include <iostream>
#include <queue>
#include <array>
#include <vector>

class Relation {
public:
  Relation(int tmp_n, int tmp_m) {
    n = tmp_n;
    m = tmp_m;
    num_of_each.fill(0);
    group.fill(0);
    group_number = 1;
  }

  void push(int s, int t) {
    V[s].push_back(t);
    V[t].push_back(s);
    num_of_each[s]++;
    num_of_each[t]++;
  }

  void makeGroup() {
    std::queue<int> Q;
    Q.push(0);
    group[0] = 1;

    for (int i = 0; i < n; i++) {
      if (group[i] == 0) {
        group[i] = ++group_number;
        Q.push(i);

        while (!Q.empty()) {
          int node = Q.front();
          Q.pop();

          for (int k = 0; k < num_of_each[node]; k++) {
            int neighbor = V[node][k];
            if (group[neighbor] == 0) {
              group[neighbor] = group[node];
              Q.push(neighbor);
            }
          }
        }
      }
    }
  }

  bool canAccess(int s, int t) {
    return group[s] == group[t];
  }

private:
  std::array<std::vector<int>, 100000> V;
  std::array<int, 100000> num_of_each;
  std::array<int, 100000> group;
  int group_number;
  int n, m;
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