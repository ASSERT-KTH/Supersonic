#include <iostream>
#include <string>
#include <queue>
#include <functional>

using namespace std;

string s;
priority_queue<string> smallest, largest;
int ans;

void dfs(string &t, int now) {
    if (now == s.size()) {
        ans++;
        if (smallest.size() < 5) {
            smallest.push(t);
        } else if (t < smallest.top()) {
            smallest.pop();
            smallest.push(t);
        }
        if (largest.size() < 5) {
            largest.push(t);
        } else if (t > largest.top()) {
            largest.pop();
            largest.push(t);
        }
        return;
    }
    int d[26] = {};
    for (int i = 0; i < now; i++) d[t[i] - 'a']++;
    if (t[now] != 'z' && d[t[now] + 1 - 'a'] == 0) {
        t[now] = t[now] + 1;
        dfs(t, now + 1);
        t[now] = t[now] - 1;
    }
    if (t[now] == 'a' || d[t[now] - 'a'] != 0) {
        dfs(t, now + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (1) {
        cin >> s;
        if (s == "#")
            break;
        smallest = priority_queue<string>();
        largest = priority_queue<string, vector<string>, greater<string>>();
        ans = 0;
        dfs(s, 0);
        cout << ans << "\n";
        while (!smallest.empty()) {
            cout << smallest.top() << "\n";
            smallest.pop();
        }
        while (!largest.empty()) {
            cout << largest.top() << "\n";
            largest.pop();
        }
    }
    return 0;
}