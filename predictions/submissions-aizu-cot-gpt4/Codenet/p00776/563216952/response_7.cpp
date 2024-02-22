#include <iostream>
#include <set>
#define rep(i, a, n) for (int i = a; i < n; i++)
using namespace std;
string s;
set<string> perms;

void dfs(int now) {
    if (now == s.size()) {
        perms.insert(s);
        return;
    }
    int d[26] = {};
    rep(i, 0, now) d[s[i] - 'a']++;
    if (s[now] != 'z' && d[s[now] + 1 - 'a'] == 0) {
        s[now] = s[now] + 1;
        dfs(now + 1);
        s[now] = s[now] - 1;  // backtrack
    }
    if (s[now] == 'a' || d[s[now] - 1 - 'a'] != 0)
        dfs(now + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (1) {
        cin >> s;
        if (s == "#")
            break;
        perms.clear();
        dfs(0);
        int ans = perms.size();
        cout << ans << endl;
        auto it = perms.begin();
        if (ans <= 10) {
            for (const auto& str : perms) {
                cout << str << endl;
            }
        } else {
            rep(i, 0, 5) { cout << *it++ << endl; }
            it = perms.end();
            rep(i, 0, 5) { cout << *--it << endl; }
        }
    }
}