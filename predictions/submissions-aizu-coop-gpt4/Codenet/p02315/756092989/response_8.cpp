#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;
    int value[n], weight[n];
    int dp_current[W+1], dp_previous[W+1];

    for (int i = 0; i < n; i++) cin >> value[i] >> weight[i];

    for (int i = 0; i <= W; i++) dp_previous[i] = 0; // initialization

    for (int i = 0; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            if (w >= weight[i]) {
                dp_current[w] = max(dp_previous[w - weight[i]] + value[i], dp_previous[w]);
            } else {
                dp_current[w] = dp_previous[w];
            }
        }
        for (int w = 0; w <= W; w++) dp_previous[w] = dp_current[w]; // updating dp_previous with dp_current
    }

    cout << dp_current[W] << endl;
    return 0;
}