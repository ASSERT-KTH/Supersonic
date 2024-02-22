void add(int a, int b) {
  g[a].push_back(b);
  g[b].push_back(a);
}