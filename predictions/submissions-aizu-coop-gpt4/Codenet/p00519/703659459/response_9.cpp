#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

vector<int> pass[6000];
int n, k;
int c[6000];
int r[6000];
int d[6000];

void dijk(int s, int g) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, s});
  while(!pq.empty()) {
    int v = pq.top().second;
    int dis = pq.top().first;
    pq.pop();
    if(d[v] != -1) continue;
    d[v] = dis;
    rep(i, r[v] + 1) {
      for(auto u : pass[v]) {
        if(d[u] == -1) {
          pq.push({dis + c[v], u});
        }
      }
    }
  }
  cout << d[g] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  rep(i, n) cin >> c[i] >> r[i];
  rep(i, k) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    pass[a].push_back(b);
    pass[b].push_back(a);
  }
  dijk(0, n - 1);
}