#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Use faster I/O methods
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr)

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

    for (int i = 0; i < state.size(); i++) {
        if (state[i] == 0) {
            cout << i << endl; // Print the vertex as it is added to the queue
            Q.push(i);
        }
    }

    while (!Q.empty()) {
        int v = Q.front();
        Q.pop();

        for (auto t : edge[v]) {
            state[t]--;
            if (state[t] == 0) {
                cout << t << endl; // Print the vertex as it is added to the queue
                Q.push(t);
            }
        }
    }

    return 0;
}