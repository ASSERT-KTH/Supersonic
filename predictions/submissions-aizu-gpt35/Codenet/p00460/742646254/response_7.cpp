#include<bits/stdc++.h>
using namespace std;
const int MAXN = 55;
const int MAXS = 3030;
const int MOD = 100000;
int dp[MAXN][MAXS];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, S;
    while(cin >> N >> M >> S && (N | M | S))
    {
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int add = 1; add <= M; add++)
        {
            for(int i = N * N; i >= 1; i--)
            {
                for(int j = S; j >= add; j--)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - add]) % MOD;
                }
            }
        }
        cout << dp[N * N][S] << endl;
    }
    return 0;
}