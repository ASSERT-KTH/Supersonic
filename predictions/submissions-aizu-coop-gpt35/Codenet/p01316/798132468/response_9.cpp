#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 20001
#define MAX_M 256

int dp[2][MAX_M];

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m), n) {
        int b[MAX_M];
        int a[MAX_N];
        
        for (int i = 0; i < m; i++) {
            scanf("%d", &b[i]);
        }
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        
        int curr = 0;
        int prev = 1;
        
        fill(dp[curr], dp[curr] + MAX_M, 1);
        
        for (int i = 0; i < n; i++) {
            swap(curr, prev);
            fill(dp[curr], dp[curr] + MAX_M, MAX_N);
            
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < MAX_M; k++) {
                    int p = k + b[j];
                    if (p > 255) p = 255;
                    if (p < 0) p = 0;
                    dp[curr][p] = min(dp[curr][p], dp[prev][k] + (a[i] - p) * (a[i] - p));
                }
            }
        }
        
        int p = MAX_N;
        for (int i = 0; i < MAX_M; i++) {
            p = min(p, dp[curr][i]);
        }
        
        printf("%d\n", p - 1);
    }
    
    return 0;
}