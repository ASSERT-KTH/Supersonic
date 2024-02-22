#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    while (cin >> n, n) {
        vector<string> directions(n);
        for (int i = 0; i < n; ++i) {
            cin >> directions[i];
        }

        int ans = 0;
        string now;
        for (const auto& next : directions) {
            if ((now == "lu" && next == "ru") || (now == "ru" && next == "lu") ||
                (now == "ld" && next == "rd") || (now == "rd" && next == "ld")) {
                ans++;
            }
            now = next;
        }

        cout << ans << endl;
    }
    
    return 0;
}