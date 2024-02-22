#include <iostream>
#include <vector>
using namespace std;

#define int long long
#define rep2(i, a, b) for (int i = (a); i < (b); i++)

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<int> lists, ans;
    bool checked[300000 + 1] = {};

    rep2(i, 2, 300000 + 1) {
        if (checked[i])
            continue;
        if (i % 7 == 1 || i % 7 == 6) {
            lists.push_back(i);
            int k = 1;
            while (i * k <= 300000) {
                checked[i * k] = true;
                k++;
            }
        }
    }

    while (true) {
        int n;
        cin >> n;
        if (n == 1)
            break;

        ans.clear();
        for (const auto &p : lists) {
            if (n % p == 0) {
                ans.push_back(p);
            }
        }

        cout << n << ':';
        for (const auto &value : ans) { 
            cout << " " << value; 
        }
        cout << endl;
    }
}