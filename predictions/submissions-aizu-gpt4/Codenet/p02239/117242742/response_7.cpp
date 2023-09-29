#include <iostream>
#include <vector>
#include <queue>

const int MAXN = 105;
std::vector<int> adj[MAXN];
bool visited[MAXN];
int distance[MAXN];
int n;

void bfs(int s) {
    std::fill(visited, visited + n, false);
    std::fill(distance, distance + n, -1);
    std::queue<int> q;
  
    visited[s] = true;
    distance[s] = 0;
    q.push(s);
  
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                distance[v] = distance[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int u, k;
        std::cin >> u >> k;
        u--;
        for (int j = 0; j < k; j++) {
            int v;
            std::cin >> v;
            v--;
            adj[u].push_back(v);
        }
    }
    bfs(0);
    for (int i = 0; i < n; i++)
        std::cout << i + 1 << ' ' << distance[i] << '\n';
  
    return 0;
}