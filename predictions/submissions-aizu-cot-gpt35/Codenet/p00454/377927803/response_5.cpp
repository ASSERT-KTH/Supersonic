#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int w, h;
int n;
vector<int> x1, x2, y1, y2;
vector<vector<bool>> fld;

void compress(vector<int>& v) {
    vector<int> xs;
    for (int i = 0; i < n; i++) {
        for (int d = -1; d <= 1; ++d) {
            int tx1 = v[i] + d, tx2 = v[i + n] + d;
            if (0 <= tx1 && tx1 <= w)
                xs.push_back(tx1);
            if (0 <= tx2 && tx2 <= w)
                xs.push_back(tx2);
        }
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    for (int i = 0; i < n; i++) {
        v[i] = lower_bound(xs.begin(), xs.end(), v[i]) - xs.begin();
        v[i + n] = lower_bound(xs.begin(), xs.end(), v[i + n]) - xs.begin();
    }
    w = xs.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> w >> h, w) {
        cin >> n;
        x1.resize(n);
        x2.resize(n);
        y1.resize(n);
        y2.resize(n);
        fld.assign(h, vector<bool>(w, false));
        for (int i = 0; i < n; i++) {
            cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        }
        compress(x1);
        compress(x2);
        compress(y1);
        compress(y2);
        for (int i = 0; i < n; i++) {
            for (int y = y1[i]; y < y2[i]; ++y) {
                for (int x = x1[i]; x < x2[i]; ++x) {
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
                    int dy[] = {-1, 0, 1, 0};
                    int dx[] = {0, -1, 0, 1};
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
        cout << ans << endl;
    }

    return 0;
}