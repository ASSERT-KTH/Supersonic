#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int N;
stringstream output;

string dfs(const string& s, int start, int end) {
    int i = start;
    long long n = -1;
    while (i < end) {
        if ('0' <= s[i] && s[i] <= '9') {
            n = (n < 0) ? s[i] - '0' : n * 10 + s[i] - '0';
            i++;
        } else if (s[i] == '(') {
            if (n < 0) n = 1;
            int cnt = 1, j = i + 1;
            while (cnt) {
                if (s[j] == '(') cnt++;
                else if (s[j] == ')') cnt--;
                j++;
            }
            string r0 = dfs(s, i + 1, j - 1);
            for (int _ = 0; _ < n; _++) {
                output << r0;
                if (output.str().size() > N) return output.str();
            }
            n = -1;
            i = j;
        } else {
            if (n < 0) n = 1;
            output << string(n, s[i]);
            n = -1;
            i++;
        }
    }
    return output.str();
}

int main() {
    for (;;) {
        string s;
        cin >> s >> N;
        if (s == "0") break;
        string result = dfs(s, 0, s.size());
        cout << (result.size() > N ? result[N] : '0') << '\n';
    }
}