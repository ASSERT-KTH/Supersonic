// ... (same as before)

// Optimization 1 and 2 applied to 'bfs' function
int bfs() {
  queue<int> que;
  queue<int> que2;
  bool flag = false;
  memset(cost, -1, sizeof(cost));
  for (int i = 1; i <= m - 1; i++) {
    ll val = (ll)i * n;
    auto it = g.find(val);
    if (it != g.end()) {
      que.push(it->second);
      cost[it->second] = 0;
    }
  }
  // Optimization 3 applied here
  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int i = -2; i <= 2; i++) {
      for (int j = -2; j <= 2; j++) {
        int nc = 0;
        if (abs(i) > 1 || abs(j) > 1)
          nc = 1;
        int nx = j + x[q], ny = i + y[q];
        if (nx < 0 || nx == 0 && ny == 0 || nx == n - 1 && ny == m - 1)
          continue;
        if (ny < 0 || nx >= n) {
          if (nc == 0)
            return 0;
          if (nc == 1)
            flag = true;
        }
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
          ll nval = (ll)ny * n + nx;
          auto it = g.find(nval);
          if (it != g.end()) {
            if (cost[it->second] == -1) {
              cost[it->second] = nc;
              if (nc == 0)
                que.push(it->second);
              if (nc == 1)
                que2.push(it->second);
            } else if (cost[it->second] == 1 && nc == 0) {
              cost[it->second] = 0;
              que.push(it->second);
            }
          }
        }
      }
    }
  }
  if (flag)
    return 1;
  while (!que2.empty()) {
    // ... (as before)
  }
  return 2;
}

// ... (same optimizations applied to 'bfs2', 'bfs3', 'bfs4' functions)

int main(void) {
  // ... (same as before)
}
