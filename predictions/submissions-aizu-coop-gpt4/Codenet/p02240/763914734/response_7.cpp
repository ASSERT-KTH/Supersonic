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
    V = new vector<int>[n];
    group = new int[n];
    for (int i = 0; i < n; i++) {
      group[i] = 0;
      unvisited.push(i);
    }
    group_number = 1;
  }

  void push(int s, int t) {
    V[s].push_back(t);
    V[t].push_back(s);
  }

  void makeGroup() {
    int node, i;
    queue<int> Q;
    Q.push(unvisited.front());
    unvisited.pop();
    group[0] = 1;
    while (!unvisited.empty()) {
      while (!Q.empty()) {
        node = Q.front();
        Q.pop();
        for (int k = 0; k < V[node].size(); k++) {
          if (group[V[node][k]] == 0) {
            group[V[node][k]] = group_number;
            Q.push(V[node][k]);
            unvisited.erase(std::find(unvisited.begin(), unvisited.end(), V[node][k]));
          }
        }
      }
      if (!unvisited.empty()) {
        group_number++;
        Q.push(unvisited.front());
        unvisited.pop();
        group[Q.back()] = group_number;
      }
    }
  }
  
  inline bool canAccsess(int s, int t) { return group[s] == group[t]; }

private:
  vector<int> *V;
  int *group;
  int group_number;
  int n, m;
  vector<int> unvisited;
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