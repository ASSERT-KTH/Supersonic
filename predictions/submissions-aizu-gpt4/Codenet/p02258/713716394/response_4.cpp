#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> R(n);
    for(auto &val : R) {
        cin >> val;
    }

    int maxProfit = *max_element(R.begin(), R.end()) - *min_element(R.begin(), R.end());
    cout << maxProfit << endl;

    return 0;
}