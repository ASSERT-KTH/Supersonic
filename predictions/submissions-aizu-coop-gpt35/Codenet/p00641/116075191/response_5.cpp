#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<vector<int>> b;
vector<vector<int>> f;
vector<bool> v;

int dfs(int s) {
  stack<int> st;
  st.push(s);
  v[s] = true;
  int maxi = f[0][s];
  int num = 1;
  int ans = 0;
  
  while (!st.empty()) {
    int now = st.top();
    st.pop();

    for (int i = 0; i < 2; i++) {
      if (!v[b[i][now]]) {
        if (maxi == f[i][now])
          num++;
        else if (maxi < f[i][now]) {
          maxi = f[i][now];
          num = 1;
        }
        if (b[i][now] == s) {
          ans += num;
        } else {
          st.push(b[i][now]);
          v[b[i][now]] = true;
        }
      }
    }
  }

  if (maxi == f[1][s])
    ans += num + 1;
  else if (maxi < f[1][s])
    ans += 1;
    
  return ans;
}

int main() {
  while (cin >> n, n) {
    b.resize(n, vector<int>(2));
    f.resize(n, vector<int>(2));
    v.resize(n, false);

    for (int i = 0; i < n; i++) {
      cin >> b[i][0] >> f[i][0] >> b[i][1] >> f[i][1];
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (!v[i]) {
        ans = (ans * dfs(i)) % 10007;
      }
    }
    cout << ans << endl;
  }
}