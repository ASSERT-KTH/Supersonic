#include <iostream>
#include <vector>
#include <numeric>
#include <cctype>
using namespace std;

constexpr int operator "" _x(char c) { return c; }

int solve(vector<string>& s, int& y, int x) {
    if (isdigit(s[y][x])) return s[y++][x] - '0';
    char op = s[y][x];
    ++y, ++x;
    vector<int> term;
    while (y < s.size() && x < s[y].size()) {
        term.push_back(solve(s, y, x));
    }
    if (op == '+') return accumulate(term.begin(), term.end(), 0);
    else return accumulate(term.begin(), term.end(), 1, multiplies<int>());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin >> n, n) {
        vector<string> s(n);
        for (auto& e : s) cin >> e;
        int y = 0;
        cout << solve(s, y, 0) << '\n';
    }
    return 0;
}