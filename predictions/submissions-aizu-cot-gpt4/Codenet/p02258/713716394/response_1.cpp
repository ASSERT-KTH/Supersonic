#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int maxProfit = 1 - 1000000000;
    int Ri = 2000000000;
    int temp;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        maxProfit = max(maxProfit, temp - Ri);
        Ri = min(Ri, temp);
    }

    cout << maxProfit << endl;
    return 0;
}