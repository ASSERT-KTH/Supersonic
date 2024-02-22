#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    while (true) {
        int n;
        cin >> n;
        if (n == 1)
            break;

        vector<int> ans;
        for (int p = 2; p * p <= n; p++) {
            while (n % p == 0) {
                ans.push_back(p);
                n /= p;
            }
        }
        if (n > 1)
            ans.push_back(n);

        cout << n << ':';
        for (int i = 0; i < ans.size(); i++) {
            cout << " " << ans[i];
        }
        cout << endl;
    }
}