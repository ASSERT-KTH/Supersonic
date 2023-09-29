#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int k;
    const int M = 10;
    while (cin >> k, k) {
        vector<int> dif(k);
        string s, t;
        cin >> s >> t;
        for (int i = 0; i < k; i++) {
            dif[i] = ((int)(t[i] - s[i]) + M) % M;
        }
        sort(dif.begin(), dif.end());
        int ans = unique(dif.begin(), dif.end()) - dif.begin();
        cout << ans << endl;
    }
}