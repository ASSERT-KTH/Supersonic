#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
int n, m, in[N], rk[N], ans[N], cnt;
vector<int> g[N];
queue<int> q;
void topo() {
  for (int i = 1; i <= n; i++)
    if (!in[i]) q.push(i);
  while (!q.empty()) {
    int u = q.front();
    ans[++cnt] = u;
    q.pop();
    for (auto v : g[u])
      if (--in[v] == 0) q.push(v);
  }
}
int main() {
  scanf("%lld %lld", &n, &m);
  while (m--) {
    int u, v;
    scanf("%lld %lld", &u, &v);
    g[u].push_back(v);
    in[v]++;
  }
  topo();
  for (int i = 1; i <= n; i++) rk[ans[i]] = i;
  bool ok = true;
  for (int i = 1; i <= n; i++)
    for (auto v : g[i])
      if (rk[i] >= rk[v]) {
        ok = false;
        break;
      }
  printf("%d\n", ok ? 0 : 1);
  for (int i = 1; i <= n; i++) printf("%lld\n", ans[i]);
  return 0;
}