#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 1e9;
const int alphabet_size = 26;

int damerau_levenshtein_distance(const string& a, const string& b) {
    int m = a.size();
    int n = b.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }

    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int cost = (a[i - 1] != b[j - 1]);
            dp[i][j] = min({dp[i - 1][j - 1] + cost, dp[i][j - 1] + 1, dp[i - 1][j] + 1});
            if (i > 1 && j > 1 && a[i - 1] == b[j - 2] && a[i - 2] == b[j - 1]) {
                dp[i][j] = min(dp[i][j], dp[i - 2][j - 2] + cost);
            }
        }
    }

    return dp[m][n];
}

void solve(int n) {
    int d;
    vector<string> name(n);

    cin >> d;

    for (int i = 0; i < n; ++i) {
        cin >> name[i];
    }

    vector<string> result;
    int count = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (damerau_levenshtein_distance(name[i], name[j]) <= d) {
                result.push_back(name[i] + "," + name[j]);
                ++count;
            }
        }
    }

    for (const auto& res : result) {
        cout << res << endl;
    }

    cout << count << endl;
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);

    for (;;) {
        int n;
        cin >> n;
        if (!n) {
            break;
        }
        solve(n);
    }

    return 0;
}