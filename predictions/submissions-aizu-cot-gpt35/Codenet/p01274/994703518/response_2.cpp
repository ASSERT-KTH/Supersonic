#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    while (cin >> n) {
        if (n == 0)
            break;

        vector<int> num(n);
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }

        sort(num.begin(), num.end());

        vector<long long> dp1(10009, 0);
        vector<long long> dp2(10006, -999999999999);

        dp2[0] = 0;

        cin >> m;

        bool flag = false;

        for (int i = 0; i < m; i++) {
            string s;
            int x, y;
            cin >> s >> x >> s >> y;

            if (x == 0 && y > 0)
                flag = true;

            if (s == "S") {
                for (int j = x; j <= 10000; j++) {
                    dp1[j] = max(dp1[j], dp1[j - x] + y);
                }
            } else {
                for (int j = x; j <= 10000; j++) {
                    dp2[j] = max(dp2[j], dp2[j - x] + y);
                }
            }
        }

        if (flag) {
            cout << "0" << endl;
            continue;
        }

        long long ans = 1ll << 60;
        long long sum;

        for (int i = 0; i < 10001; i++) {
            if (dp2[i] < 0)
                continue;

            sum = i;

            for (int j = 0; j < n; j++) {
                int pos = lower_bound(dp1.begin(), dp1.end(), num[j] - dp2[i]) - dp1.begin();
                sum += pos;
            }

            ans = min(ans, sum);
        }

        cout << ans << endl;
    }

    return 0;
}