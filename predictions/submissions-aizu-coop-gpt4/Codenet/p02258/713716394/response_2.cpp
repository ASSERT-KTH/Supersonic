#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int maxProfit = INT32_MIN;
    int minPrice = INT32_MAX;
    int price;

    for (int i = 0; i < n; i++) {
        cin >> price;
        maxProfit = max(maxProfit, price - minPrice);
        minPrice = min(minPrice, price);
    }

    cout << maxProfit << endl;
    return 0;
}