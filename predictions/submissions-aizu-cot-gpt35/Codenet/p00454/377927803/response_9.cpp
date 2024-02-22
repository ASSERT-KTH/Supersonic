#include <iostream>
#include <set>
#include <vector>
using namespace std;

int w, h;
int n;
int x1[1005], x2[1005];
int y1[1005], y2[1005];
vector<int> dsu;
vector<bool> fld;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int find(int x) {
    if (dsu[x] == x) {
        return x;
    }
    return dsu[x] = find(dsu[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        dsu[x] = y;
    }
}

int compress(int *x1, int *x2, int w) {
    set<int> xs;
    for (int i = 0; i < n; ++i) {
        for (int d = -1; d <= 1; ++d) {
            int tx1 = x1[i] + d, tx2 = x2[i] + d;
            if (0 <= tx1 && tx1 <= w)
                xs.insert(tx1);
            if (0 <= tx2 && tx2 <= w)
                xs.insert(tx2);
        }
    }
    int compressed_w = xs.size();
    for (int i = 0; i < n; ++i) {
        x1[i] = distance(xs.begin(), xs.find(x1[i]));
        x2[i] = distance(xs.begin(), xs.find(x2[i]));
    }
    return compressed_w;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> w >> h, w) {
        cin >> n;
        dsu.resize(w * h);
        fld.assign(w * h, false);
        for (int i = 0; i < n; ++i) {
            cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        }
        w = compress(x1, x2, w);
        h = compress(y1, y2, h);
        for (int i = 0; i < w * h; ++i) {
            dsu[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int y = y1[i]; y <= y2[i] - 1; ++y) {
                for (int x = x1[i]; x <= x2[i] - 1; ++x) {
                    fld[y * w + x] = true;
                }
            }
        }
        int ans = 0;
        for (int y = 0; y < h - 1; ++y) {
            for (int x = 0; x < w - 1; ++x) {
                if (fld[y * w + x])
                    continue;
                ans++;
                for (int i = 0; i < 4; ++i) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if (ny < 0 || ny >= h - 1 || nx < 0 || nx >= w - 1 || fld[ny * w + nx])
                        continue;
                    merge(y * w + x, ny * w + nx);
                }
            }
        }
        set<int> distinct_sets;
        for (int i = 0; i < w * h; ++i) {
            if (!fld[i]) {
                distinct_sets.insert(find(i));
            }
        }
        ans += distinct_sets.size();
        cout << ans << endl;
    }
    return 0;
}