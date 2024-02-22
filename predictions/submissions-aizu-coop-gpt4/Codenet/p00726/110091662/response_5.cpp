#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int N;

string dfs(const string &s, int start, int end) {
    string r;
    long long n = -1;
    for (int i = start; i < end;) {
        if ('0' <= s[i] && s[i] <= '9') {
            if (n < 0)
                n = s[i] - '0';
            else
                n = n * 10 + s[i] - '0';
            i++;
        } else if (s[i] == '(') {
            if (n < 0)
                n = 1;
            int cnt = 1, j = i + 1;
            for (; cnt; j++) {
                if (s[j] == '(')
                    cnt++;
                else if (s[j] == ')')
                    cnt--;
            }
            string r0 = dfs(s, i + 1, j - 1);
            for (int _ = 0; _ < n && r.size() <= N; _++) {
                r += r0;
            }
            n = -1;
            i = j;
        } else {
            if (n < 0)
                n = 1;
            for (int _ = 0; _ < n && r.size() <= N; _++) {
                r += s[i];
            }
            n = -1;
            i++;
        }
        if (r.size() > N)
            break;
    }
    return r;
}

int main() {
    for (;;) {
        string s;
        cin >> s >> N;
        if (s == "0")
            break;
        string r = dfs(s, 0, s.size());
        printf("%c\n", r.size() > N ? r[N] : '0');
    }
}