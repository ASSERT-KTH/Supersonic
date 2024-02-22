#include <iostream>
#include <array>
#include <algorithm>
#include <map>

using namespace std;

struct QuickFind {
    array<int, 100000> r, p;
    array<array<int, 100000>, 100000> v;

    QuickFind() {}

    QuickFind(int size) { init(size); }

    void init(int size) {
        fill(r.begin(), r.begin() + size, 0);
        fill(p.begin(), p.begin() + size, 0);
        for (int i = 0; i < size; i++) {
            r[i] = 1, p[i] = i;
            v[i][0] = i;
        }
    }

    bool same(int x, int y) { return p[x] == p[y]; }

    void unite(int x, int y) {
        x = p[x];
        y = p[y];
        if (x == y)
            return;
        if (r[x] < r[y])
            swap(x, y);
        r[x] += r[y];
        for (int i = 0; i < r[y]; i++) {
            p[v[y][i]] = x;
            v[x][r[x] + i] = v[y][i];
        }
    }
};

int main() {
    int n;
    cin >> n;
    array<int, 100000> a;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.begin() + n);
    QuickFind qf(n);
    for (int i = 0; i < n; i++)
        qf.unite(i, i);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int k = qf.r[i];
        if (qf.p[i] != i || k == 1)
            continue;
        int m = a[qf.v[i][0]];
        int tmp = 0;
        for (int j = 0; j < k; j++) {
            tmp += a[qf.v[i][j]];
            m = min(m, a[qf.v[i][j]]);
        }
        ans += min(tmp + m * (k - 2), tmp + m + a[0] * (k + 1));
    }
    cout << ans << endl;
    return 0;
}