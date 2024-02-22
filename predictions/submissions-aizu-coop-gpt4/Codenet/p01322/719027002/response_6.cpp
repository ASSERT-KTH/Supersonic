#include <iostream>
#include <unordered_map>

using namespace std;

// Function to check if a string matches the pattern
bool matchPattern(const string& pattern, const string& s) {
    for (int i = 0; i < 8; i++) {
        if (pattern[i] != '*' && pattern[i] != s[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m, value;
    string pattern, s;
    unordered_map<string, int> patterns; // Unordered_map to store the patterns and their values

    while (true) {
        cin >> n >> m;
        if (!n && !m)
            break;
        
        patterns.clear(); // Clear the map for each test case
        int ans = 0;

        // Input the patterns and their corresponding values
        for (int i = 0; i < n; i++) {
            cin >> pattern >> value;
            patterns[pattern] = value;
        }

        // Check if each string matches any pattern
        for (int i = 0; i < m; i++) {
            cin >> s;
            for (const auto& p : patterns) {
                if (matchPattern(p.first, s)) {
                    ans += p.second;
                    break;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}