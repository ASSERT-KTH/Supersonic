#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int N;

string dfs(const string& s, size_t& idx) {
    string r;
    long long reps = -1;
    while (idx < s.size()) {
        if (isdigit(s[idx])) {
            if (reps < 0) reps = s[idx] - '0';
            else reps = reps * 10 + s[idx] - '0';
            idx++;
        } else if (s[idx] == '(') {
            if (reps < 0) reps = 1;
            idx++;
            string sub = dfs(s, idx);
            for (long long _ = 0; _ < reps; _++) {
                r += sub;
                if (r.size() > N) return r;
            }
            reps = -1;
        } else if (s[idx] == ')') {
            idx++;
            return r;
        } else {
            if (reps < 0) reps = 1;
            r += string(reps, s[idx]);
            reps = -1;
            idx++;
        }
    }
    return r;
}

int main() {
    for (;;) {
        string s;
        cin >> s >> N;
        if (s == "0") break;
        size_t idx = 0;
        string r = dfs(s, idx);
        printf("%c\n", r.size() > N ? r[N] : '0');
    }
}