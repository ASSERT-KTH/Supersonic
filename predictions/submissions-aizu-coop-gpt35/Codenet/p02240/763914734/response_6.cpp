void makeGroup() {
  int node, i;
  queue<int> Q;
  Q.push(0);
  group[0] = 1;
  while (!Q.empty()) {
    node = Q.front();
    Q.pop();
    for (int k = 0; k < V[node].size(); k++) {
      if (group[V[node][k]] == 0) {
        group[V[node][k]] = group[node];
        Q.push(V[node][k]);
      }
    }
  }
}