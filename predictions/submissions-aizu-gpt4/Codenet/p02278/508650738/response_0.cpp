#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define int long long
struct DisjointSet {
    vector<int> rank, parent, sum, minVal;
    DisjointSet(int size) {
        rank.resize(size, 1);
        parent.resize(size);
        sum.resize(size, 0);
        minVal.resize(size, INT64_MAX);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (rank[x] < rank[y]) swap(x, y);
            parent[y] = x;
            minVal[x] = min(minVal[x], minVal[y]);
            sum[x] += sum[y];
            if (rank[x] == rank[y]) ++rank[x];
        }
    }
};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> sortedA(a);
    sort(sortedA.begin(), sortedA.end());
    map<int, int> position;
    for (int i = 0; i < n; i++) position[sortedA[i]] = i;
    DisjointSet ds(n);
    for (int i = 0; i < n; i++) {
        ds.minVal[i] = ds.sum[i] = a[i];
        ds.unite(i, position[a[i]]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (ds.find(i) == i) 
            ans += min(ds.sum[i] + ds.minVal[i] * (ds.rank[i] - 2), ds.sum[i] + ds.minVal[i] + sortedA[0] * (ds.rank[i] + 1));
    cout << ans;
    return 0;
}