bool visited[100010];

void decomp(int root) {
  rep(i, n) visited[i] = false;
  queue<int> q;
  q.push(root);
  vector<int> tord;
  while (q.size()) {
    int v = q.front();
    q.pop();
    visited[v] = true;
    tord.push_back(v);
    for (int c : g[v]) {
      if (!visited[c]) {
        q.push(c);
      }
    }
  }
  rep(i, n) visited[i] = false;
  int c = 0;
  for (int u : tord) {
    if (visited[u]) {
      continue;
    }
    q.push(u);
    int k = 0;
    while (q.size() && k < B) {
      int v = q.front();
      q.pop();
      visited[v] = true;
      color[v] = c;
      parent[v] = par[u];
      k++;
      for (int c : g[v]) {
        if (!visited[c]) {
          q.push(c);
        }
      }
    }
    while (q.size()) {
      q.pop();
    }
    c++;
  }
}