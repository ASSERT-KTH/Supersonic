#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;

void getPermutations(string s, int start, vector<string> &result) {
    if (start == s.length()) {
        result.push_back(s);
        return;
    }
    for (int i = start; i < s.size(); i++) {
        swap(s[start], s[i]);
        getPermutations(s, start + 1, result);
        swap(s[start], s[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (cin >> s) {
        if (s == "#") break;
        vector<string> result;
        getPermutations(s, 0, result);
        sort(result.begin(), result.end());
        cout << result.size() << endl;
        if (result.size() <= 10) {
            for (const auto &str : result) {
                cout << str << "\n";
            }
        } else {
            for (int i = 0; i < 5; i++) {
                cout << result[i] << "\n";
            }
            for (int i = result.size() - 5; i < result.size(); i++) {
                cout << result[i] << "\n";
            }
        }
    }
    return 0;
}