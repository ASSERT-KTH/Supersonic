// Code snippet
// Replace static arrays with dynamic vectors
vector<int> pre(V_MAX);
vector<U> d(V_MAX);

// Replace priority_queue with vector
vector<pair<U, int>> Q;

// Replace map with unordered_map or vector
unordered_map<int, int> f[100][2]; // if keys are not continuous
vector<int> f[100][2]; // if keys are continuous

// Avoid redundant computations
T temp = e.capa - e.flow;
if (temp > 0 && cost2 < d[e.v]) {
    // use temp in the calculation
}

// Loop unrolling
// Depending on the maximum size of G[u], manually unroll the loop
for(int i = 0; i < G[u].size(); i+=2) {
    edge<T, U> &e = G[u][i];
    // Do something with e
    edge<T, U> &e_next = G[u][i+1];
    // Do something with e_next
}