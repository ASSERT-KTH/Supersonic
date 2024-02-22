#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int N;

string dfs(const string &s, int &i) {
    stringstream r;
    long long n = -1;
    while(i < s.size()) {
        if ('0' <= s[i] && s[i] <= '9') {
            n = (n < 0) ? (s[i] - '0') : (n * 10 + s[i] - '0');
            i++;
        } else if (s[i] == '(') {
            n = (n < 0) ? 1 : n;
            int cnt = 1, j = i + 1;
            while(cnt) {
                if (s[j] == '(')
                    cnt++;
                else if (s[j] == ')')
                    cnt--;
                j++;
            }
            i++;
            string r0 = dfs(s, i);
            for(int _ = 0; _ < n; _++) {
                r << r0;
                if(r.str().size() > N)
                    return r.str().substr(0, N+1);
            }
            n = -1;
            i = j;
        } else {
            n = (n < 0) ? 1 : n;
            for(int _ = 0; _ < n; _++)
                r << s[i];
            if(r.str().size() > N)
                return r.str().substr(0, N+1);
            n = -1;
            i++;
        }
    }
    return r.str();
}

int main() {
    for (;;) {
        string s;
        cin >> s >> N;
        if (s == "0")
            break;
        int start = 0;
        string r = dfs(s, start);
        printf("%c\n", r.size() > N ? r[N] : '0');
    }
}