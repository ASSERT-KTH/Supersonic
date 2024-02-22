template <class T, class U>
pair<T, U> augment(int n, vector<edge<T, U>> *G, int s, int t, U *pot) {
  ...
  rep(i, G[u].size()) {
    edge<T, U> &e = G[u][i];
    U cost2 = cost + e.cost + pot[u] - pot[e.v]; // store the value in a variable
    if (e.capa - e.flow > 0 && cost2 < d[e.v]) {
      d[e.v] = cost2;
      pre[e.v] = e.rev;
      Q.push(make_pair(-cost2, e.v));
    }
  }
  ...
}