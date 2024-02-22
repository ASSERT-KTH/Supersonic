#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

unordered_map<pair<vector<int>, int>, int> mp;

int search(const vector<int>& vi, int depth, int used, int m, int n, const vector<string>& qes) {
    if (mp.count(make_pair(vi, used))) {
        return mp[make_pair(vi, used)];
    }

    int res = 100;
    for (int i = 0; i < m; i++) {
        if ((used >> i) & 1) {
            continue;
        }

        vector<int> a, b;
        for (int j : vi) {
            if (qes[j][i] == '0') {
                a.push_back(j);
            } else {
                b.push_back(j);
            }
        }

        if (a.empty() || b.empty()) {
            continue;
        }

        res = min(res, max(search(a, depth + 1, used | (1 << i), m, n, qes),
                           search(b, depth + 1, used | (1 << i), m, n, qes)));
    }

    return mp[make_pair(vi, used)] = res;
}

int main() {
    int m, n;
    while (cin >> m >> n, m) {
        vector<string> qes(n);
        for (string& q : qes) {
            cin >> q;
        }

        vector<int> vi(n);
        for (int i = 0; i < n; i++) {
            vi[i] = i;
        }

        mp.clear();
        cout << search(vi, 0, 0, m, n, qes) << endl;
    }

    return 0;
}