#include <bits/stdc++.h>
using namespace std;

int solve(string &s, int &idx) {
    if (idx >= s.size()) return 0;
    
    if (isdigit(s[idx])) return s[idx++] - '0';
    
    char op = s[idx++];
    
    int ans = (op == '+') ? 0 : 1;
    while (idx < s.size()) {
        if (op == '+') ans += solve(s, idx);
        else ans *= solve(s, idx);
    }
    
    return ans;
}

int main(void) {
    int n;
    while (cin >> n, n) {
        string s;
        for (int i = 0; i < n; ++i) {
            string tmp; cin >> tmp;
            s += tmp;
        }
        int idx = 0;
        cout << solve(s, idx) << endl;
    }
    return 0;
}