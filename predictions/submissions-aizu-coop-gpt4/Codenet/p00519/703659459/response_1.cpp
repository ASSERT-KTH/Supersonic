#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define INF 999999999

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> c(n), r(n);
    for(int i=0; i<n; i++) cin >> c[i] >> r[i];
    vector<vector<int>> pass(n);
    for(int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        pass[a].push_back(b);
        pass[b].push_back(a);
    }
    vector<int> d(n, INF);
    d[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        int v, dist_v;
        tie(dist_v, v) = pq.top();
        pq.pop();
        if (d[v] < dist_v) continue;
        for (int u : pass[v]) {
            if (d[u] > d[v] + c[v]) {
                d[u] = d[v] + c[v];
                pq.push({d[u], u});
            }
        }
    }
    cout << d[n-1] << endl;
}