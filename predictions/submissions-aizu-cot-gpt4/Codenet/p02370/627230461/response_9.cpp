#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
using namespace std;

int main() {
  int V, E;
  cin >> V >> E;
  
  vector<vector<int>> edge(V);
  vector<int> state(V, 0);
  
  for (int i = 0; i < E; i++) {
    int s, t;
    cin >> s >> t;
    edge[s].push_back(t);
    state[t]++;
  }
  
  deque<int> ans;
  for (int i = 0; i < V; i++) {
    if (state[i] == 0)
      ans.push_front(i);
  }
  
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < edge[ans[i]].size(); j++) {
      int t = edge[ans[i]][j];
      state[t]--;
      if (state[t] == 0)
        ans.push_front(t);
    }
  }
  
  stringstream ss;
  for (int i = 0; i < ans.size(); i++) {
    ss << ans[i] << endl;
  }
  
  cout << ss.str();
  
  return 0;
}