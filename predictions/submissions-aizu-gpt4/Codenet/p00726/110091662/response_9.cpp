#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

ll N;

pair<string, ll> dfs(const string &s, ll start) {
    string res;
    ll num = -1;
    for (ll i = start; i < s.size();) {
        if (isdigit(s[i])) {
            if (num < 0) num = s[i] - '0';
            else num = num * 10 + (s[i] - '0');
            i++;
        } else if (s[i] == '(') {
            if (num < 0) num = 1;
            i++;
            ll cnt = 1;
            ll j = i;
            while (cnt) {
                if (s[j] == '(') cnt++;
                else if (s[j] == ')') cnt--;
                j++;
            }
            pair<string, ll> rec_res = dfs(s, i);
            for (int _ = 0; _ < num; _++) {
                res += rec_res.first;
                if (res.size() > N) return make_pair(res, j+1);
            }
            num = -1;
            i = rec_res.second;
        } else {
            if (num < 0) num = 1;
            for (int _ = 0; _ < num; _++) {
                res += s[i];
                if (res.size() > N) return make_pair(res, i+1);
            }
            num = -1;
            i++;
        }
    }
    return make_pair(res, s.size());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (true) {
        string s;
        cin >> s >> N;
        if (s == "0") break;
        pair<string, ll> res = dfs(s, 0);
        cout << (res.first.size() > N ? res.first[N] : '0') << "\n";
    }
    return 0;
}