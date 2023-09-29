#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int inf = 1e9;
constexpr int MAX = 1005 * 6 + 2;
int fld[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int w, h, n;
vector<int> x1, x2, y1, y2;

int compress(vector<int> &x1, vector<int> &x2, int w) {
    vector<int> xs;
    for (int i = 0; i < n; i++) {
        for (int d = -1; d <= 1; d++) {
            int tx1 = x1[i] + d, tx2 = x2[i] + d;
            if (0 <= tx1 && tx1 < w)
                xs.push_back(tx1);
            if (0 <= tx2 && tx2 < w)
                xs.push_back(tx2);
        }
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    for (int i = 0; i < n; i++) {
        x1[i] = lower_bound(xs.begin(), xs.end(), x1[i]) - xs.begin();
        x2[i] = lower_bound(xs.begin(), xs.end(), x2[i]) - xs.begin();
    }
    return xs.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> w >> h, w) {
        cin >> n;
        x1.resize(n); x2.resize(n); y1.resize(n); y2.resize(n);
        fill(&fld[0][0], &fld[MAX][0], 0);

        for (int i = 0; i < n; i++) {
            cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        }

        w = compress(x1, x2, w);
        h = compress(y1, y2, h);

        for (int i = 0; i < n; i++) {
            for (int y = y1[i]; y < y2[i]; y++) {
                for (int x = x1[i]; x < x2[i]; x++) {
                    fld[y][x] = true;
                }
            }
        }

        int ans = 0;
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                if (fld[y][x])
                    continue;
                ans++;

                queue<pair<int, int>> q;
                q.push(make_pair(y, x));

                while (!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();

                    for (int i = 0; i < 4; i++) {
                        int ny = p.first + dy[i], nx = p.second + dx[i];
                        if (ny < 0 || ny >= h || nx < 0 || nx >= w || fld[ny][nx])
                            continue;
                        fld[ny][nx] = true;
                        q.push(make_pair(ny, nx));
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}