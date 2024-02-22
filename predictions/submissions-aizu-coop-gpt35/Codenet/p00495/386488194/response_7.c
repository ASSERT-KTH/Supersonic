#include <stdio.h>

#define MAX_COINS 5004

int main() {
    int c[MAX_COINS], d[MAX_COINS];
    int n_coins, i, sum, coin, min_coins;

    scanf("%d%*d", &n_coins);
    
    for (i = 0; i < n_coins; i++) {
        scanf("%d", &c[i]);
    }
    
    while (scanf("%d", &sum) != EOF) {
        min_coins = sum + 1;

        for (i = 0; i < n_coins; i++) {
            coin = c[i];
            if (coin <= sum && d[coin] < min_coins) {
                min_coins = d[coin] + 1;
            }
        }

        for (i = 0; i < n_coins; i++) {
            coin = c[i];
            if (coin <= sum && d[coin] + 1 < d[sum]) {
                d[sum] = d[coin] + 1;
            }
        }
    }

    printf("%d\n", d[sum]);

    return 0;
}