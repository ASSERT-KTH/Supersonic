#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(string& s, vector<string>& vs, int now) {
    if (now == s.size()) {
        vs.push_back(s);
        return;
    }
    dfs(s, vs, now + 1);
    for (int i = now + 1; i < s.size(); i++) {
        if (s[now] != s[i]) {
            swap(s[now], s[i]);
            dfs(s, vs, now + 1);
            swap(s[now], s[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while (cin >> s && s != "#") {
        vector<string> vs;
        dfs(s, vs, 0);
        int ans = vs.size();
        cout << ans << endl;
        if (ans <= 10) {
            for (int i = 0; i < ans; i++) {
                cout << vs[i] << endl;
            }
        } else {
            for (int i = 0; i < 5; i++) {
                cout << vs[i] << endl;
            }
            for (int i = ans - 5; i < ans; i++) {
                cout << vs[i] << endl;
            }
        }
    }
    return 0;
}