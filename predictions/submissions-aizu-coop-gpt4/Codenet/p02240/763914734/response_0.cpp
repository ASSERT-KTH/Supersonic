#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Relation {
public:
  Relation(int tmp_n) : n(tmp_n), group(tmp_n, 0), V(tmp_n) {}
  
  void push(int s, int t) {
    V[s].push_back(t);
    V[t].push_back(s);
  }

  void makeGroup() {
    int group_number = 1;
    unordered_set<int> unvisited;
    for(int i=0; i<n; i++) unvisited.insert(i);
    while (!unvisited.empty()) {
      queue<int> Q;
      int node = *unvisited.begin();
      Q.push(node);
      unvisited.erase(node);
      group[node] = group_number;
      while (!Q.empty()) {
        node = Q.front();
        Q.pop();
        for (int k : V[node]) {
          if (group[k] == 0) {
            group[k] = group[node];
            Q.push(k);
            unvisited.erase(k);
          }
        }
      }
      group_number++;
    }
  }
  
  bool canAccsess(int s, int t) { return group[s] == group[t]; }

private:
  vector<vector<int>> V;
  vector<int> group;
  int n;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
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