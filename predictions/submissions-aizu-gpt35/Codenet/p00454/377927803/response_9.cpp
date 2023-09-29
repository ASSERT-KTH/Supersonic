#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

constexpr int MAX_N = 1005;
bool fld[MAX_N * 6 + 2][MAX_N * 6 + 2];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int compress(int *x1, int *x2, int w, int n) {
    vector<int> xs;
    for (int i = 0; i < n; ++i) {
        for (int d = -1; d <= 1; ++d) {
            int tx1 = x1[i] + d, tx2 = x2[i] + d;
            if (0 <= tx1 && tx1 <= w) xs.push_back(tx1);
            if (0 <= tx2 && tx2 <= w) xs.push_back(tx2);
        }
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    for (int i = 0; i < n; ++i) {
        x1[i] = lower_bound(xs.begin(), xs.end(), x1[i]) - xs.begin();
        x2[i] = lower_bound(xs.begin(), xs.end(), x2[i]) - xs.begin();
    }
    return xs.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        int w, h, n;
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        cin >> n;
        fill(&fld[0][0], &fld[MAX_N * 6 + 2][0], false);
        int x1[MAX_N], x2[MAX_N], y1[MAX_N], y2[MAX_N];
        for (int i = 0; i < n; ++i) {
            cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        }
        w = compress(x1, x2, w, n);
        h = compress(y1, y2, h, n);
        for (int i = 0; i < n; ++i) {
            for (int y = y1[i]; y < y2[i]; ++y) {
                for (int x = x1[i]; x < x2[i]; ++x) {
                    fld[y][x] = true;
                }
            }
        }
        int ans = 0;
        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                if (fld[y][x]) continue;
                ++ans;
                queue<pair<int, int>> que;
                que.push(make_pair(y, x));
                while (!que.empty()) {
                    int i = que.front().first;
                    int j = que.front().second;
                    que.pop();
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + dy[k];
                        int nj = j + dx[k];
                        if (ni >= 0 && ni < h && nj >= 0 && nj < w && !fld[ni][nj]) {
                            fld[ni][nj] = true;
                            que.push(make_pair(ni, nj));
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}