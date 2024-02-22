#include <iostream>
#include <vector>
#include <deque>
using namespace std;

#define int long long
typedef vector<int> vint;
typedef pair<int, int> pint;
typedef vector<pint> vpint;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, f, n) for (int i = (f); i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define each(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define pb push_back
#define fi first
#define se second

const int MAX_VALUE = 10000;
const int MAX_COIN = 6;
const int MAX_AMOUNT = 2500;

int C[MAX_COIN] = {1, 5, 10, 50, 100, 500};
int P;
int N[MAX_COIN];

int coinCount[MAX_VALUE];
int dp[2][MAX_VALUE];

int calc(int v)
{
    return coinCount[v];
}

signed main()
{
    // Pre-calculate the number of coins needed for each value
    for (int v = 1; v <= MAX_VALUE; v++)
    {
        int ans = 0;
        for (int i = MAX_COIN - 1; i >= 0; i--)
        {
            ans += v / C[i];
            v %= C[i];
        }
        coinCount[v] = ans;
    }

    while (cin >> P)
    {
        rep(i, MAX_COIN)
                cin >>
            N[i];
        if (P == 0)
            break;

        // Initialize dp array
        fill_n(*dp, 2 * MAX_VALUE, 1001001001);
        int cnt = 0;
        for (int i = MAX_COIN - 1; i >= 0; i--)
        {
            while (P - C[i] >= MAX_AMOUNT && N[i])
            {
                cnt++;
                N[i]--;
                P -= C[i];
            }
            if (N[i])
                break;
        }
        dp[0][0] = 0;

        rep(i, MAX_COIN)
        {
            rep(j, C[i])
            {
                int deq[MAX_VALUE];
                int deqSize = 0;

                for (int k = j; k < MAX_VALUE; k += C[i])
                {
                    int w = MAX_VALUE - k / C[i];
                    if (dp[i % 2][k] + w < dp[(i + 1) % 2][k])
                        dp[(i + 1) % 2][k] = dp[i % 2][k] + w;

                    while (deqSize > 0 && dp[i % 2][k] + w < deq[deqSize - 1])
                        deqSize--;

                    if (deqSize > 0 && deq[deqSize - 1] + N[i] * C[i] <= k)
                        deqSize--;

                    deq[deqSize++] = dp[i % 2][k] + w;
                }
            }
        }
        int mi = 1001001001;
        for (int i = P; i < MAX_VALUE; i++)
        {
            if (dp[0][i] + calc(i - P) < mi)
                mi = dp[0][i] + calc(i - P);
        }
        cout << mi + cnt << endl;
    }
    return 0;
}
