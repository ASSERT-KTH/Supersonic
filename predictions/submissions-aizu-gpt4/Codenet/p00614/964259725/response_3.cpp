#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_CHANGE = 3001, MAX_VAL = 1e7;
int coinValue[6] = {1, 5, 10, 50, 100, 500};
int coinCnt[6], DP[2][MAX_CHANGE];

int main() {
    int payment;
    while (cin >> payment) {
        for (int i = 0; i < 6; ++i) cin >> coinCnt[i];
        if (payment == 0) break;

        fill(DP[0], DP[0] + MAX_CHANGE, MAX_VAL);
        DP[0][0] = 0;
        for (int i = 0; i < 6; ++i) {
            fill(DP[(i + 1) % 2], DP[(i + 1) % 2] + MAX_CHANGE, MAX_VAL);
            for (int j = 0; j < coinValue[i]; ++j) {
                deque<pair<int, int>> deq;
                for (int k = j; k < MAX_CHANGE; k += coinValue[i]) {
                    if (!deq.empty() && deq.front().second < k - coinCnt[i] * coinValue[i]) deq.pop_front();
                    if (!deq.empty()) DP[(i + 1) % 2][k] = min(DP[(i + 1) % 2][k], deq.front().first);
                    pair<int, int> newPair = {DP[i % 2][k] + (k + coinValue[i] - 1) / coinValue[i], k};
                    while (!deq.empty() && deq.back().first >= newPair.first) deq.pop_back();
                    deq.push_back(newPair);
                }
            }
            for (int j = 0; j < MAX_CHANGE; ++j) DP[(i + 1) % 2][j] = min(DP[(i + 1) % 2][j], DP[i % 2][j]);
        }
        int minimumCoins = MAX_VAL;
        for (int i = payment; i < MAX_CHANGE; ++i) minimumCoins = min(minimumCoins, DP[0][i] + i - payment);
        cout << minimumCoins << "\n";
    }
    return 0;
}