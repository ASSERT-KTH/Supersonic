#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edge(V);
    vector<int> state(V, 0);
    for (int i = 0; i < E; ++i) {
        int s, t;
        cin >> s >> t;
        edge[s].push_back(t);
        ++state[t];
    }
    queue<int> ans;
    for (int i = 0; i < V; ++i) {
        if (state[i] == 0)
            ans.push(i);
    }
    while (!ans.empty()) {
        int i = ans.front();
        ans.pop();
        cout << i << '\n';
        for (int t : edge[i]) {
            if (--state[t] == 0)
                ans.push(t);
        }
    }
    return 0;
}