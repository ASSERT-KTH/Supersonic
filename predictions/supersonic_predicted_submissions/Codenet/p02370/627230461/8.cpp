#include <iostream>
#include <vector>
using namespace std;
int main() {
  int V, E;
  cin >> V >> E;
  vector<int> edge[10001];
  vector<int> state(V, 0);
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    edge[s - 1].push_back(t);
    state[t]++;
  }
  vector<int> ans;
  for (int i = 0; i < state.size(); i++) {
    if (state[i] == 0)
      ans.push_back(i);
  }
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < edge[ans[i]].size(); j++) {
      int t = edge[ans[i]][j];
      state[t]--;
      if (state[t] == 0)
        ans.push_back(t);
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
