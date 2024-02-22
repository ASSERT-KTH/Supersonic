#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;

void appendChar(vector<char>& result, char c, long long n) {
    for (int i = 0; i < n && result.size() <= N; ++i) {
        result.push_back(c);
    }
}

void parseString(const string& s, int start, int end, vector<char>& result) {
    long long n = -1;
    for (int i = start; i < end && result.size() <= N;) {
        if ('0' <= s[i] && s[i] <= '9') {
            n = (n < 0 ? 0 : n * 10) + (s[i] - '0');
            ++i;
        } else if (s[i] == '(') {
            if (n < 0)
                n = 1;
            int cnt = 1, j = i + 1;
            for (; cnt;) {
                if (s[j] == '(')
                    ++cnt;
                else if (s[j] == ')')
                    --cnt;
                ++j;
            }
            for (int _ = 0; _ < n && result.size() <= N; _++) {
                parseString(s, i + 1, j - 1, result);
            }
            n = -1;
            i = j;
        } else {
            if (n < 0)
                n = 1;
            appendChar(result, s[i], n);
            n = -1;
            ++i;
        }
    }
}

int main() {
    for (;;) {
        string s;
        cin >> s >> N;
        if (s == "0")
            break;
        vector<char> result;
        parseString(s, 0, s.size(), result);
        cout << ((result.size() > N) ? result[N] : '0') << "\n";
    }
    return 0;
}