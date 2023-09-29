#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100;
const int INFTY = (1 << 21);

struct Edge {
    int to;
    int weight;
};

vector<Edge> graph[MAX];
int dist[MAX];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    fill(dist, dist + MAX, INFTY);
    dist[start] = 0;
    PQ.push(make_pair(0, start));

    while(!PQ.empty()) {
        pair<int, int> f = PQ.top(); PQ.pop();
        int u = f.second;
        if(dist[u] < f.first) continue;

        for(auto j = graph[u].begin(); j != graph[u].end(); ++j) {
            if(dist[j->to] > dist[u] + j->weight) {
                dist[j->to] = dist[u] + j->weight;
                PQ.push(make_pair(dist[j->to], j->to));
            }
        }
    }
}

int main() {
    int n, u, k, v, c;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> u >> k;
        for (int j = 0; j < k; ++j) {
            cin >> v >> c;
            graph[u].push_back((Edge){v, c});
        }
    }

    dijkstra(0);
    for (int i = 0; i < n; ++i) {
        cout << i << " " << ((dist[i] == INFTY) ? -1 : dist[i]) << endl;
    }
    return 0;
}