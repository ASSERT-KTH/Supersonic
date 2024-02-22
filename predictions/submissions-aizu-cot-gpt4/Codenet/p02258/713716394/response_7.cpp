#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int n;
    cin >> n;
    int maxProfit = -2e9;
    int minPrice = 2e9;

    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        maxProfit = max(maxProfit, price - minPrice);
        minPrice = min(minPrice, price);
    }
    cout << maxProfit << "\n";
    return 0;
}