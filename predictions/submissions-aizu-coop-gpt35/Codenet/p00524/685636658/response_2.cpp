#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int V = 100000;
const int VV = 1000000;
const ll INF = LLONG_MAX / 3;

struct edge {
  int to;
  ll cost;
};

vector<vector<edge>> G(V);
vector<vector<edge>> gg(VV);
vector<set<int>> height(V);

int n, m;
ll X;
int H[V];
int max_h[V] = {};
ll d[VV];

int main() {
  scanf(" %d %d %lld", &n, &m, &X);
  
  for (int i = 0; i < n; i++) {
    scanf(" %d", &H[i]);
  }
  
  for (int i = 0; i < m; i++) {
    int a, b, t;
    scanf(" %d %d %d", &a, &b, &t);
    --a;
    --b;
    G[a].push_back({b, t});
    G[b].push_back({a, t});
  }
  
  int ct = 1;
  priority_queue<pair<ll, int>> que;
  que.push(make_pair(X, 0));
  height[0].insert(X);
  
  while (!que.empty()) {
    pair<ll, int> p = que.top();
    que.pop();
    int v = p.second, h = p.first;
    
    if (h < max_h[v])
      continue;
    
    for (const auto &e : G[v]) {
      int bh = h;
      int nh = h - e.cost;
      
      if (nh < 0)
        continue;
      
      if (nh > H[e.to]) {
        bh = H[e.to] + e.cost;
        nh = H[e.to];
      }
      
      if (nh > max_h[e.to]) {
        if (!height[v].count(bh)) {
          height[v].insert(bh);
        }
        
        if (!height[e.to].count(nh)) {
          height[e.to].insert(nh);
        }
        
        int uu = ct++;
        int vv = ct++;
        gg[uu].push_back({vv, e.cost});
        max_h[e.to] = nh;
        que.push(make_pair(max_h[e.to], e.to));
      }
    }
  }
  
  for (int i = 0; i < n; i++) {
    for (const auto &e : G[i]) {
      if (H[i] < e.cost)
        continue;
      
      if (!height[i].count(e.cost)) {
        height[i].insert(e.cost);
      }
      
      if (!height[e.to].count(0)) {
        height[e.to].insert(0);
      }
      
      int uu = ct++;
      int vv = ct++;
      gg[uu].push_back({vv, e.cost});
    }
  }
  
  if (!height[n - 1].count(H[n - 1])) {
    height[n - 1].insert(H[n - 1]);
  }
  
  for (int i = 0; i < n; i++) {
    int S = height[i].size();
    auto itr = height[i].begin();
    
    for (int j = 0; j < S - 1; j++) {
      auto nx = itr;
      ++nx;
      int uu = *itr;
      int vv = *nx;
      int dist = vv - uu;
      gg[uu].push_back({vv, dist});
      gg[vv].push_back({uu, dist});
      itr = nx;
    }
  }
  
  int start = 0;
  int goal = n - 1;
  
  fill(d, d + VV, INF);
  d[start] = 0;
  
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
  pq.push(make_pair(0, start));
  
  while (!pq.empty()) {
    pair<ll, int> now = pq.top();
    pq.pop();
    int v = now.second;
    
    if (now.first > d[v])
      continue;
    
    for (const auto &e : gg[v]) {
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        pq.push(make_pair(d[e.to], e.to));
      }
    }
  }
  
  ll ans = d[goal];
  
  if (ans == INF)
    ans = -1;
  
  printf("%lld\n", ans);
  
  return 0;
}