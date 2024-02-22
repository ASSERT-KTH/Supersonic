#include <iostream>
#include <vector>

class Relation {
public:
  Relation(int tmp_n, int tmp_m) : n(tmp_n), m(tmp_m), V(tmp_n), num_of_each(tmp_n), group(tmp_n) {
    group_number = 1;
  }

  void push(int s, int t) {
    V[s].push_back(t);
    V[t].push_back(s);
    num_of_each[s]++;
    num_of_each[t]++;
  }

  void makeGroup() {
    std::vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(i, group_number);
        group_number++;
      }
    }
  }

  bool canAccsess(int s, int t) {
    return group[s] == group[t];
  }

private:
  void dfs(int node, int group_num) {
    visited[node] = true;
    group[node] = group_num;
    for (int neighbor : V[node]) {
      if (!visited[neighbor]) {
        dfs(neighbor, group_num);
      }
    }
  }

  std::vector<std::vector<int>> V;
  std::vector<int> num_of_each;
  std::vector<int> group;
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
    if (relation.canAccsess(s, t)) {
      std::cout << "yes\n";
    } else {
      std::cout << "no\n";
    }
  }
  return 0;
}