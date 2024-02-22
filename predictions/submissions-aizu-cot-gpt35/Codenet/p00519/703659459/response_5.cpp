#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int MAX_N = 6000;
const int INF = numeric_limits<int>::max();

vector<int> pass[MAX_N];
int n, k;
int c[MAX_N];
int r[MAX_N];
int d[MAX_N];
bool used[MAX_N];

void dijk(int s, int g) {
    fill(d, d + n, INF);
    d[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();

        if (used[v])
            continue;
        
        used[v] = true;

        for (int u : pass[v]) {
            int new_dist = d[v] + c[v];

            if (new_dist < d[u]) {
                d[u] = new_dist;
                pq.push({d[u], u});
            }
        }
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> c[i] >> r[i];
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        pass[a].push_back(b);
        pass[b].push_back(a);
    }

    dijk(0, n - 1);

    cout << d[n - 1] << endl;

    return 0;
}