#include <iostream>
using namespace std;

int n, **b, **f, *v;

int dfs(int s, int now, int maxi, int num) {
  v[now] = true;

  if (!v[b[0][now]]) {
    if (maxi == f[0][now])
      num++;
    else if (maxi < f[0][now]) {
      maxi = f[0][now];
      num = 1;
    }
    if (b[0][now] == s)
      return num;

    return dfs(s, b[0][now], maxi, num);
  }

  if (!v[b[1][now]]) {
    if (maxi == f[1][now])
      num++;
    else if (maxi < f[1][now]) {
      maxi = f[1][now];
      num = 1;
    }
    if (b[1][now] == s)
      return num;

    return dfs(s, b[1][now], maxi, num);
  }

  if (maxi == f[1][s])
    return num + 1;
  else if (maxi < f[1][s])
    return 1;
  else
    return num;
}

int main() {
  #pragma GCC optimize("unroll-loops")
  #pragma GCC optimize("inline")

  while (cin >> n, n) {
    b = new int*[n];
    f = new int*[n];
    v = new int[n];

    for (int i = 0; i < n; i++) {
      b[i] = new int[2];
      f[i] = new int[2];
      cin >> b[i][0] >> f[i][0] >> b[i][1] >> f[i][1];
      v[i] = false;
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (!v[i]) {
        v[i] = true;
        ans = (ans * dfs(i, b[i][0], f[i][0], 1)) % 10007;
      }
    }

    cout << ans << endl;

    for (int i = 0; i < n; i++) {
      delete[] b[i];
      delete[] f[i];
    }
    delete[] b;
    delete[] f;
    delete[] v;
  }
}