#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> R(n);
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }

    int maxProfit = INT_MIN; // it's safer to use INT_MIN which is the lowest possible integer
    int Ri = R[0]; // initialize with the first element of the array

    for (const auto& price : R) {
        maxProfit = max(maxProfit, price - Ri);
        Ri = min(Ri, price);
    }

    cout << maxProfit << endl;
    return 0;
}