#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, a, b) for (int i = (a); i <= (b); ++i)
#define rep3(i, a, b) for (int i = (a); i >= (b); --i)
const int INF = 1001001001;
const ll LINF = 1LL << 60;
const int MAX_V = 100000;
vector<P> to[MAX_V];
int V, E, r;
int dist[MAX_V];
void dijkstra(int s) {
    priority_queue<Pl, vector<Pl>, greater<Pl>> q;
    fill(dist, dist + V, INF);
    dist[s] = 0;
    q.push(Pl(0, s));
    while (!q.empty()) {
        Pl p = q.top();
        q.pop();
        int v = p.second;
        if (dist[v] < p.first)
            continue;
        for (auto x : to[v]) {
            int nv = x.first;
            int nd = p.first + x.second;
            if (dist[nv] > nd) {
                dist[nv] = nd;
                q.push(Pl(dist[nv], nv));
            }
        }
    }
}
int main() {
    cin >> V >> E >> r;
    rep(i, E) {
        int s, t, d;
        cin >> s >> t >> d;
        to[s].push_back(make_pair(t, d));
    }
    dijkstra(r);
    rep(i, V) {
        if (dist[i] == INF)
            cout << "INF" << endl;
        else
            cout << dist[i] << endl;
    }
    return 0;
}