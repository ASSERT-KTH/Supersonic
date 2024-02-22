#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Use fast I/O operations
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
    FAST_IO;

    int V, E;
    cin >> V >> E;

    vector<vector<int>> edge(V);
    vector<int> state(V, 0);
    queue<int> Q;

    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        edge[s].push_back(t);
        state[t]++;
    }

    for (int i = 0; i < V; i++) {
        if (state[i] == 0)
            Q.push(i);
    }

    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        cout << node << endl;
        for (auto &t : edge[node]) {
            state[t]--;
            if (state[t] == 0)
                Q.push(t);
        }
    }

    return 0;
}