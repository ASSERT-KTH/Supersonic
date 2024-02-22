#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int damerau_levenshtein_distance(string a, string b, int alphabet_size) {
    vector<int> da(alphabet_size, 0);
    vector<vector<int>> d(a.size() + 1, vector<int>(b.size() + 1, 0));
    int maxdist = a.size() + b.size();
    d[0][0] = maxdist;
    for (int i = 1; i <= a.size(); ++i) {
        d[i][0] = i;
    }
    for (int i = 1; i <= b.size(); ++i) {
        d[0][i] = i;
    }
    for (int i = 1; i <= a.size(); ++i) {
        int db = 0;
        for (int j = 1; j <= b.size(); ++j) {
            int k = da[b[j - 1]], l = db, cost;
            if (a[i - 1] == b[j - 1]) {
                cost = 0;
                db = j;
            } else {
                cost = 1;
            }
            d[i][j] = min({d[i - 1][j - 1] + cost, d[i][j - 1] + 1, d[i - 1][j] + 1,
                           d[k][l] + (i - k - 1) + 1 + (j - l - 1)});
        }
        da[a[i - 1]] = i;
    }
    return d[a.size()][b.size()];
}

void solve(int n) {
    int d;
    cin >> d;
    vector<string> name(n);
    for (int i = 0; i < n; ++i) {
        cin >> name[i];
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (damerau_levenshtein_distance(move(name[i]), move(name[j]), 26) > d) {
                continue;
            }
            ++count;
            cout << name[i] << "," << name[j] << endl;
        }
    }
    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(10);
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        solve(n);
    }
    return 0;
}