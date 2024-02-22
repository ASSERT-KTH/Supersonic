edge<T, U>** G = new edge<T, U>*[V_MAX];
for (int u = 0; u < V_MAX; u++) {
    G[u] = new edge<T, U>[V_MAX];
}