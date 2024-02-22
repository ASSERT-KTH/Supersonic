#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<pair<int, int>> adj[100100];
bool visited[100100];

int dfs(int start) {
  stack<int> st;
  st.push(start);
  int maxi = 0, num = 0;
  while (!st.empty()) {
    int now = st.top();
    st.pop();
    visited[now] = true;
    for (auto &i : adj[now]) {
      if (!visited[i.first]) {
        st.push(i.first);
        if (maxi == i.second)
          num++;
        else if (maxi < i.second) {
          maxi = i.second;
          num = 1;
        }
      }
    }
  }
  return num;
}

int main() {
  int n;
  while (cin >> n, n) {
    for (int i = 0; i < n; i++) {
      int b1, f1, b2, f2;
      cin >> b1 >> f1 >> b2 >> f2;
      adj[i].push_back({b1, f1});
      adj[i].push_back({b2, f2});
      visited[i] = false;
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
      if (!visited[i])
        ans = (ans * dfs(i)) % 10007;
    cout << ans << endl;
  }
  return 0;
}