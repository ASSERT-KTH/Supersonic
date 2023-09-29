#include <iostream>
#include <string>
using namespace std;

inline int parseNumber(const string& s, int& i) {
    int n = 0;
    while (i < s.size() && isdigit(s[i])) {
        n = n * 10 + (s[i++] - '0');
    }
    return n ? n : 1;
}

string dfs(const string& s, int& i, int N) {
    string r;
    while (i < s.size() && r.size() <= N) {
        if (isdigit(s[i])) {
            int n = parseNumber(s, i);
            r.append(n, s[i++]);
        }
        else if (s[i] == '(') {
            int n = parseNumber(s, ++i);
            string t = dfs(s, i, n * (N / n + 1));
            while (n-- && r.size() <= N) r += t;
            i++;
        }
    }
    return r;
}

int main() {
    for (;;) {
        string s;
        int N;
        cin >> s >> N;
        if (s == "0") break;
        int i = 0;
        string r = dfs(s, i, N);
        cout << (r.size() > N ? r[N] : '0') << "\n";
    }
}