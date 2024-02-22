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
    V.resize(n);
    group.resize(n, 0);
    visited.resize(n, false);
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
    visited[0] = true;
    
    while (!Q.empty() || (i = find_unvisited()) != -1) {
      if(Q.empty() && i != -1) {
        Q.push(i);
        group[i] = ++group_number;
      }
      
      while (!Q.empty()) {
        node = Q.front();
        Q.pop();
        for (int k : V[node]) {
          if (!visited[k]) {
            visited[k] = true;
            group[k] = group[node];
            Q.push(k);
          }
        }
      }
    }
  }
  
  bool canAccess(int s, int t) {
    return group[s] == group[t];
  }

private:
  vector<vector<int>> V;
  vector<int> group;
  vector<bool> visited;
  int group_number;
  int n, m;
  
  int find_unvisited() {
    for(int i = 0; i < n; i++) {
      if(!visited[i]) {
        return i;
      }
    }
    return -1;
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