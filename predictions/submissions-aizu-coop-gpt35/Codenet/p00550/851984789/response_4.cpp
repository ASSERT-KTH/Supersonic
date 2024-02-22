#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;

const int MAX_NODES = 110000;
const int MAX_EDGES = 210000;

int n, q, a[MAX_EDGES], b[MAX_EDGES], dist[MAX_NODES], T[MAX_NODES], cnt;
vector<vector<int>> graph(MAX_NODES), rev_graph(MAX_NODES);
bitset<MAX_EDGES> used;
bitset<MAX_NODES> U;

void bfs(int source) {
    fill(dist, dist + n + 1, 999999);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v : graph[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

void dfs(int u) {
    for (int v : rev_graph[u]) {
        if (dist[u] < dist[v]) {
            T[v]++;
            if (--T[v] == 0 && !U[v]) {
                U[v] = true;
                cnt++;
                dfs(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i] >> b[i];
        graph[a[i]].push_back(b[i]);
        rev_graph[b[i]].push_back(a[i]);
    }

    bfs(1);

    for (int i = 0; i < n - 1; i++) {
        if (dist[a[i]] < dist[b[i]]) {
            T[b[i]]++;
        } else {
            T[a[i]]++;
        }
    }

    while (q--) {
        int c;
        cin >> c;
        c--;

        int ss = -1;
        if (dist[a[c]] < dist[b[c]]) {
            ss = b[c];
        } else if (dist[a[c]] > dist[b[c]]) {
            ss = a[c];
        }

        if (ss >= 1 && !U[ss] && !used[c]) {
            stack<pair<int, int>> stk;
            stk.push(make_pair(ss, c));

            while (!stk.empty()) {
                int u = stk.top().first;
                int v = stk.top().second;
                stk.pop();

                if (U[u] || used[v]) {
                    continue;
                }

                used[v] = true;
                if (--T[u] == 0) {
                    U[u] = true;
                    cnt++;
                    dfs(u);
                }

                for (int w : rev_graph[u]) {
                    if (!U[w]) {
                        stk.push(make_pair(w, -1));
                    }
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}