#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int solve(vector<string>& s, int n, int& y, int x) {
    if (isdigit(s[y][x]))
        return s[y++][x] - '0';
  
    char op = s[y][x];
    ++y, ++x;
  
    vector<int> term;
    for (; y < n && s[y].size() > x; ++y) {
        term.push_back(solve(s, n, y, x));
    }
  
    return op == '+' ? accumulate(term.begin(), term.end(), 0) : accumulate(term.begin(), term.end(), 1, multiplies<int>());
}

int main(void) {
    int n;
    while (cin >> n, n) {
        vector<string> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        int y = 0;
        cout << solve(s, n, y, 0) << endl;
    }
    return 0;
}