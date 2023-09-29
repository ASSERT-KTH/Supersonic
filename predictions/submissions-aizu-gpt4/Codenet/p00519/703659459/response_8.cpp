#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define INF 999999999
vector<int> pass[6000];
int n, k;
int c[6000];
int r[6000];
int d[6000];
bool used[6000];
queue<int> que;

void bfs(int v, int f, int end) {
  fill(used, used+n, false);
  que.push(v);
  used[v] = true;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    if (f < end) {
      for (int i : pass[u]) {
        if (!used[i]) {
          d[i] = min(d[i], d[v] + c[v]);
          que.push(i);
          used[i] = true;
        }
      }
    }
  }
}

int dijk(int s, int g) {
  fill(d, d+n, INF);
  d[s] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> que;
  que.push(pii(0, s));
  while (!que.empty()) {
    int v = que.top().second;
    que.pop();
    if (v == g) break;
    bfs(v, 1, r[v]);
    for (int i : pass[v]) {
      if (d[i] > d[v] + c[v]) {
        d[i] = d[v] + c[v];
        que.push(pii(d[i], i));
      }
    }
  }
  return d[g];
}

int main() {
  cin >> n >> k;
  rep(i, n) cin >> c[i] >> r[i];
  rep(i, k) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    pass[a].pb(b);
    pass[b].pb(a);
  }
  cout << dijk(0, n - 1) << endl;
}