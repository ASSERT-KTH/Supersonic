#include <stdio.h>
#include <vector>

class Relation {
public:
  Relation(int tmp_n, int tmp_m) {
    n = tmp_n;
    m = tmp_m;
    V.resize(m);
    num_of_each.resize(n, 0);
    group.resize(n, 0);
    group_number = 1;
  }

  void push(const int& s, const int& t) {
    V.push_back({s, t});
    num_of_each[s]++;
    num_of_each[t]++;
  }

  void makeGroup() {
    for (int i = 0; i < n; i++) {
      if (group[i] == 0) {
        group[i] = group_number;
        dfs(i);
        group_number++;
      }
    }
  }

  bool canAccess(const int& s, const int& t) {
    return group[s] == group[t];
  }

private:
  std::vector<std::pair<int, int>> V;
  std::vector<int> num_of_each;
  std::vector<int> group;
  int group_number;
  int n, m;

  void dfs(int node) {
    for (const auto& edge : V) {
      int s = edge.first;
      int t = edge.second;
      if (s == node && group[t] == 0) {
        group[t] = group[node];
        dfs(t);
      } else if (t == node && group[s] == 0) {
        group[s] = group[node];
        dfs(s);
      }
    }
  }
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