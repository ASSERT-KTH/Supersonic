#include <iostream>
#include <stack>
using namespace std;
int n, b[2][100100], f[2][100100];
bool v[100100];
struct Node { int s, now, maxi, num; };
int dfs(int s, int now, int maxi, int num) {
  stack<Node> st;
  st.push({s, now, maxi, num});
  while (!st.empty()) {
    Node node = st.top();
    st.pop();
    v[node.now] = true;
    for (int i = 0; i < 2; i++) {
      if (!v[b[i][node.now]]) {
        if (node.maxi == f[i][node.now])
          node.num++;
        else if (node.maxi < f[i][node.now]) {
          node.maxi = f[i][node.now];
          node.num = 1;
        }
        if (b[i][node.now] == node.s)
          return node.num;
        st.push({node.s, b[i][node.now], node.maxi, node.num});
      }
    }
    if (node.maxi == f[1][node.s])
      return node.num + 1;
    else if (node.maxi < f[1][node.s])
      return 1;
    else
      return node.num;
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(false); // improve I/O performance
  cin.tie(NULL);
  while (cin >> n, n) {
    for (int i = 0; i < n; i++) {
      cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
      v[i] = false;
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (!v[i]) {
        v[i] = true;
        ans = (ans * dfs(i, b[0][i], f[0][i], 1)) % 10007;
      }
    }
    cout << ans << endl;
  }
}