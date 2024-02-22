#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int maxProfit = INT_MIN;
    int minPrice = INT_MAX;
    for (int i = 0; i < n; i++) {
        int currPrice;
        cin >> currPrice;
        minPrice = min(minPrice, currPrice);
        maxProfit = max(maxProfit, currPrice - minPrice);
    }
    cout << maxProfit << endl;
    return 0;
}