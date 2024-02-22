int find(int join[], int x) {
  int root = x;
  while (root != join[root])
    root = join[root];
  // Path compression
  while (x != root) {
    int next = join[x];
    join[x] = root;
    x = next;
  }
  return root;
}