#include <stdio.h>
#include <limits.h>

#define MAX_COINS 5004

int main() {
    int coins[MAX_COINS];
    int dp[MAX_COINS];
    int numOfCoins, targetAmount, currentAmount, coinIndex, minCoins, temp;

    scanf("%d%*d", &numOfCoins);
    for (coinIndex = 0; coinIndex < numOfCoins; coinIndex++) {
        scanf("%d", &coins[coinIndex]);
    }

    scanf("%d", &targetAmount);

    for (currentAmount = 0; currentAmount <= targetAmount; currentAmount++) {
        dp[currentAmount] = INT_MAX;
    }
    dp[0] = 0;

    for (currentAmount = 1; currentAmount <= targetAmount; currentAmount++) {
        minCoins = INT_MAX;
        for (coinIndex = 0; coinIndex < numOfCoins; coinIndex++) {
            if (coins[coinIndex] <= currentAmount) {
                temp = dp[currentAmount - coins[coinIndex]];
                if (temp != INT_MAX && temp + 1 < minCoins) {
                    minCoins = temp + 1;
                }
            }
        }
        dp[currentAmount] = minCoins;
    }

    printf("%d\n", dp[targetAmount]);

    return 0;
}