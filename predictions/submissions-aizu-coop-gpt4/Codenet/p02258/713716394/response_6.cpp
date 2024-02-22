#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int maxProfit = INT_MIN;
    int minPrice = INT_MAX;
    int currentPrice;

    for (int i = 0; i < n; i++) {
        cin >> currentPrice;
        if (currentPrice - minPrice > maxProfit)
            maxProfit = currentPrice - minPrice;
        if (currentPrice < minPrice)
            minPrice = currentPrice;
    }

    cout << maxProfit << endl;
    return 0;
}