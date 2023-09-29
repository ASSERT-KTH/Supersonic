#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int MAX = 100;
const int INFTY = INT_MAX;
typedef pair<int, int> P;

int n;
vector<P> M[MAX];

void dijkstra() {
    priority_queue<P, vector<P>, greater<P>> pq;
    int d[MAX];
    fill(d, d + n, INFTY);
    d[0] = 0;
    pq.push(P(0, 0));

    while (!pq.empty()) {
        P f = pq.top(); pq.pop();
        int u = f.second;
        if (d[u] < f.first) continue;
        for (auto &j : M[u]) {
            int v = j.first;
            if (d[v] > d[u] + j.second) {
                d[v] = d[u] + j.second;
                pq.push(P(d[v], v));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
    }
}

int main() {
    cin >> n;
    int k, c, u, v;
    for (int i = 0; i < n; i++) {
        cin >> u >> k;
        for (int j = 0; j < k; j++) {
            cin >> v >> c;
            M[u].push_back(P(v, c));
        }
    }
    dijkstra();
    return 0;
}