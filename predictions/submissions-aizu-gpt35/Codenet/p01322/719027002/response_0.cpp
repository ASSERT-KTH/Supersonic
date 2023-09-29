#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    for (;;) {
        cin >> n >> m;
        if (!n && !m) {
            break;
        }
        unordered_map<string, int> prices;
        for (int i = 0; i < n; i++) {
            string name;
            int price;
            cin >> name >> price;
            prices[name] = price;
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            string item;
            cin >> item;
            ans += prices[item];
        }
        cout << ans << endl;
    }

    return 0;
}