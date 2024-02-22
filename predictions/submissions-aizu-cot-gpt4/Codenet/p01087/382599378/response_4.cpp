#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); ++i)

int solve(std::string &s, int &y, int x) {
    if (isdigit(s[y]))
        return s[y++] - '0';
    char op = s[y++];
    int result = (op == '+') ? 0 : 1;
    while (y < s.size() && s[y] != ' ') {
        int term = solve(s, y, x);
        if(op == '+')
            result += term;
        else
            result *= term;
    }
    return result;
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n) {
        std::string s;
        rep(i, n) {
            std::string temp;
            std::cin >> temp;
            s += temp + " ";
        }
        int y = 0;
        printf("%d\n", solve(s, y, 0));
    }
    return 0;
}