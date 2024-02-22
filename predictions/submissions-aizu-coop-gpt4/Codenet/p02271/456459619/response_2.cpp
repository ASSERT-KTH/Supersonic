#include <cstdio>
using namespace std;

int *N;
int n;

bool subsetSum(int sum) {
    bool dp[n+1][sum+1];
    for (int i=0; i<=n; i++)
        dp[i][0] = true;
    for (int i=1; i<=sum; i++)
        dp[0][i] = false;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=sum; j++){
            if (j < N[i-1])
                dp[i][j] = dp[i-1][j];
            if (j >= N[i-1])
                dp[i][j] = dp[i-1][j] || dp[i - 1][j-N[i-1]];
        }
    }
    return dp[n][sum];
}

int main() {
    int t;
    scanf("%d", &n);
    N = new int[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &N[i]);
    }
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int p;
        scanf("%d", &p);
        if (subsetSum(p)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    delete[] N;
    return 0;
}