#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, m, value;
    string pattern;
    int ans;
    for (;;) {
        cin >> n >> m;
        if (!n && !m)
            break;
        ans = 0;
        unordered_map<string, int> pattern_value;
        for (int i = 0; i < n; i++) {
            cin >> pattern >> value;
            pattern_value[pattern] = value;
        }
        for (int i = 0; i < m; i++) {
            string l;
            cin >> l;
            for (const auto& pair : pattern_value) {
                bool match = true;
                for (int k = 0; k < 8; k++) {
                    if (pair.first[k] != '*' && pair.first[k] != l[k]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    ans += pair.second;
                }
            }
        }
        cout << ans << endl;
    }
}