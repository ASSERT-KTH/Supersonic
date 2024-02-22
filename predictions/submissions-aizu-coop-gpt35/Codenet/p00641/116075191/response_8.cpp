#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> edges;

int dfs(int s, int now, int maxi, int num) {
  for (const auto& edge : edges[now]) {
    if (edge.first == s) {
      if (maxi == edge.second)
        return num;
      else if (maxi < edge.second)
        return 1;
      else
        return num;
    }
    int result = dfs(s, edge.first, max(maxi, edge.second), maxi == edge.second ? num + 1 : 1);
    if (result != 0)
      return result;
  }
  return num;
}

int main() {
  #pragma GCC optimize("O3")
  while (cin >> n, n) {
    edges.clear();
    edges.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> edges[i].first >> edges[i].second >> edges[i].first >> edges[i].second;
    }
    int ans = 1;
    int visited = 0;
    for (int i = 0; i < n; i++) {
      if (visited < n) {
        ans = (ans * dfs(i, edges[i].first, edges[i].second, 1)) % 10007;
        visited++;
      }
    }
    cout << ans << endl;
  }
}