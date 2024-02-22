#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int inf = 1e9;

int damerau_levenshtein_distance(const string &a, const string &b, const int alphabet_size) {
    vector<int> da(26, 0);
    vector<vector<int>> d(a.size() + 1, vector<int>(b.size() + 1, inf));

    d[-1][-1] = a.size() + b.size();
    for (int i = 0; i <= a.size(); ++i) {
        d[i][-1] = a.size() + b.size();
        d[i][0] = i;
    }
    for (int i = 0; i <= b.size(); ++i) {
        d[-1][i] = a.size() + b.size();
        d[0][i] = i;
    }
    
    for (int i = 1; i <= a.size(); ++i) {
        int db = 0;
        for (int j = 1; j <= b.size(); ++j) {
            int k = da[b[j - 1]], l = db, cost;
            if (a[i - 1] == b[j - 1]) {
                cost = 0;
                db = j;
            } else
                cost = 1;
            d[i][j] = min({d[i - 1][j - 1] + cost, d[i][j - 1] + 1, d[i - 1][j] + 1,
                           d[k - 1][l - 1] + (i - k - 1) + 1 + (j - l - 1)});
        }
        da[a[i - 1] - 'a'] = i;
    }

    return d[a.size()][b.size()];
}

void solve(int n) {
    int d;
    vector<string> name;
    cin >> d;
    name.reserve(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        name.push_back(s);
    }
    sort(name.begin(), name.end());

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (damerau_levenshtein_distance(name[i], name[j], 26) > d)
                continue;
            ++count;
            cout << name[i] << "," << name[j] << endl;
        }
    }
    cout << count << endl;
}

int main() {
    for (;;) {
        int n;
        cin >> n;
        if (!n)
            break;
        solve(n);
    }
    return 0;
}