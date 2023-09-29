#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

inline int min(int a, int b, int c, int d) {
    return min(min(a, b), min(c, d));
}

int damerau_levenshtein_distance(const string &a, const string &b) {
    vector<int> da(256);
    vector<vector<int>> d(a.size() + 2, vector<int>(b.size() + 2));
    int inf = a.size() + b.size();
    d[0][0] = inf;
    for (int i = 0; i <= a.size(); i++) {
        d[i + 1][1] = i;
        d[i + 1][0] = inf;
    }
    for (int i = 0; i <= b.size(); i++) {
        d[1][i + 1] = i;
        d[0][i + 1] = inf;
    }
    for (int i = 1; i <= a.size(); i++) {
        int db = 0;
        for (int j = 1; j <= b.size(); j++) {
            int i1 = da[b[j - 1]];
            int j1 = db;
            int cost = (a[i - 1] == b[j - 1] ? 0 : 1);
            if (cost == 0) db = j;
            d[i + 1][j + 1] = min(d[i][j] + cost, d[i + 1][j] + 1, d[i][j + 1] + 1, d[i1][j1] + (i - i1 - 1) + 1 + (j - j1 - 1));
        }
        da[a[i - 1]] = i;
    }
    return d[a.size() + 1][b.size() + 1];
}

void solve(int n) {
    int d;
    cin >> d;
    vector<string> name(n);
    for (int i = 0; i < n; ++i) cin >> name[i];
    sort(name.begin(), name.end());
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (damerau_levenshtein_distance(name[i], name[j]) > d)
                continue;
            cout << name[i] << "," << name[j] << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while (cin >> n, n != 0) solve(n);
    return 0;
}