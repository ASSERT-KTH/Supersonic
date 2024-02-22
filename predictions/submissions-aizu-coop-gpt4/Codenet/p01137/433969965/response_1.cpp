#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int targetNumber;
    while (cin >> targetNumber, targetNumber) {
        int minSum = INT_MAX;
        for (int z = 0; z * z * z <= targetNumber; ++z) {
            for (int y = 0; y * y + z * z * z <= targetNumber; ++y) {
                int x = targetNumber - (y * y + z * z * z);
                minSum = min(minSum, x + y + z);
                if(y * y + z * z * z > targetNumber) {
                    break;
                }
            }
        }
        cout << minSum << endl;
    }
    return 0;
}