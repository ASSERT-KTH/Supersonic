#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> N;
vector<vector<int>> memo;

int solve(int i, int m) {
    if(m == 0) return 1;
    if(i >= N.size()) return 0;
    if(memo[i][m] != -1) return memo[i][m];
    if(m - N[i] >= 0 && solve(i + 1, m - N[i])) return memo[i][m] = 1;
    return memo[i][m] = solve(i + 1, m);
}

int main() {
    int n, t;
    cin >> n;
    N.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> N[i];
    }
    cin >> t;
    memo.resize(n, vector<int>(2001, -1));
    for (int i = 0; i < t; i++) {
        int p;
        cin >> p;
        cout << (solve(0, p) ? "yes" : "no") << endl;
    }
    return 0;
}