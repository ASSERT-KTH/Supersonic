#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unordered_map<string, string> direction = {{"lu", "ru"}, {"ru", "lu"}, {"ld", "rd"}, {"rd", "ld"}};
  
    int n;
    while (cin >> n, n) {
        int ans = 0;
        string now, next;
        for(int i = 0; i < n; ++i) {
            cin >> next;
            if (direction[now] == next)
                ans++;
            now = next;
        }
        cout << ans << "\n";
    }
    return 0;
}