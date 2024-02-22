#include <cstdio>
#include <vector>
using namespace std;
int main() {
  int V, E;
  scanf("%d %d", &V, &E);
  vector<vector<int>> edge(V);
  vector<int> state(V, 0);
  for (int i = 0; i < E; i++) {
    int s, t;
    scanf("%d %d", &s, &t);
    edge[s].push_back(t);
    state[t]++;
  }
  vector<int> ans;
  for (int i = 0; i < V; i++) {
    if (state[i] == 0)
      ans.push_back(i);
  }
  for (auto i : ans) {
    for (auto j : edge[i]) {
      state[j]--;
      if (state[j] == 0)
        ans.push_back(j);
    }
  }
  for (auto i : ans) {
    printf("%d\n", i);
  }
  return 0;
}