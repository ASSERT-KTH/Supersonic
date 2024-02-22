#include <algorithm>
#include <iostream>
#include <vector>
#define INF 1 << 28
using namespace std;
vector<int> p;
vector<vector<int>> memo;
vector<int> memo2;

void solve(int n) {
    for (int i = 0; i <= n; i++) {
        for (int count = 0; count <= 5; count++) {
            if (!i || !count) {
                memo[i][count] = 0;
                continue;
            }
            int ans = INF;
            for (int j = 0; j <= i && p[j] <= i; j++)
                ans = min(ans, memo[i - p[j]][count - 1] + 1);
            memo[i][count] = ans;
        }
    }
}

void solve2(int n) {
    for (int i = 0; i <= n; i++) {
        if (!i) {
            memo2[i] = 0;
            continue;
        }
        int ans = INF;
        for (int j = 0; j <= i && p[j] <= i; j++) {
            if (!(p[j] % 2))
                continue;
            ans = min(ans, memo2[i - p[j]] + 1);
        }
        memo2[i] = ans;
    }
}

int main() {
    int n;
    p.resize(1000001);
    memo.resize(1000001, vector<int>(6, 0));
    memo2.resize(1000001, 0);
    for (int i = 0; i <= 1000000; i++)
        p[i] = i * (i + 1) * (i + 2) / 6;
    solve(1000000);
    solve2(1000000);
    while (cin >> n, n)
        cout << memo[n][5] << " " << memo2[n] << endl;
}