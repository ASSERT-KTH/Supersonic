#include <algorithm>
#include <queue>
#include <stdio.h>
#include <vector>
using namespace std;

class Relation {
public:
  Relation(int tmp_n, int tmp_m) : n(tmp_n), m(tmp_m), group_number(1), V(new vector<int>[n]), num_of_each(new int[n]()), group(new int[n]()) {}

  void push(int s, int t) {
    V[s].push_back(t);
    V[t].push_back(s);
    num_of_each[s]++;
    num_of_each[t]++;
  }

  void makeGroup() {
    queue<int> Q;
    Q.push(0);
    group[0] = 1;
    while (true) {
      while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        if (num_of_each[node] > 0) {
          vector<int>& v_node = V[node];
          for (int k = 0; k < num_of_each[node]; ++k) {
            if (group[v_node[k]] == 0) {
              group[v_node[k]] = group[node];
              Q.push(v_node[k]);
            }
          }
        }
      }
      group_number++;
      int i = 0;
      for (; i < n; ++i) {
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
  vector<int> *V;
  int *num_of_each;
  int *group;
  int group_number;
  int n, m;
};

int main() {
  int n, m, s, t, q;
  scanf("%d %d", &n, &m);
  Relation relation(n, m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &s, &t);
    relation.push(s, t);
  }
  relation.makeGroup();
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    scanf("%d %d", &s, &t);
    if (relation.canAccsess(s, t)) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }
  return 0;
}