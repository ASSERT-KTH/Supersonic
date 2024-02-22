#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cstring>
using namespace std;

const int MAXN = 110000;
const int MAXM = 210000;

int n, m, q, a[MAXM], b[MAXM], c, dist[MAXN], T[MAXN], cnt, U[MAXN];
vector<vector<int>> x(MAXN), y(MAXN);
vector<bool> used(MAXM);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> q;

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        x[a[i]].push_back(b[i]);
        x[b[i]].push_back(a[i]);
    }

    memset(dist, 0x3F, sizeof(dist));
    dist[1] = 0;

    deque<int> Q;
    Q.push_back(1);

    while (!Q.empty()) {
        int a1 = Q.front();
        Q.pop_front();

        for (int i : x[a1]) {
            if (dist[i] > dist[a1] + 1) {
                dist[i] = dist[a1] + 1;
                Q.push_back(i);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j : x[i]) {
            if (dist[i] < dist[j]) {
                y[i].push_back(j);
                T[j]++;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> c;
        c--;

        deque<pair<int, int>> Q1;
        int ss = -1;

        if (dist[a[c]] < dist[b[c]])
            ss = b[c];
        if (dist[a[c]] > dist[b[c]])
            ss = a[c];

        if (ss >= 1 && U[ss] == 0 && !used[c]) {
            Q1.push_back(make_pair(ss, c));

            while (!Q1.empty()) {
                int a1 = Q1.front().first, a2 = Q1.front().second;
                Q1.pop_front();

                if (U[a1] == 1 || used[a2])
                    continue;

                T[a1]--;
                used[a2] = true;

                if (T[a1] != 0)
                    continue;

                cnt++;
                U[a1] = 1;

                for (int j : y[a1]) {
                    if (U[j] == 0)
                        Q1.push_back(make_pair(j, 0));
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}