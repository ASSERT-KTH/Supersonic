#include <iostream>
#include <string>
#include <functional>

int solve(std::vector<std::string> &s, int n, int &y, int x) {
    if (isdigit(s[y][x]))
        return s[y++][x] - '0';
    
    char op = s[y][x];
    ++y, ++x;
    int result = (op == '+') ? 0 : 1;
    
    while (y < n && s[y].size() > x) {
        int term = solve(s, n, y, x);
        if (op == '+')
            result += term;
        else
            result *= term;
    }
    
    return result;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    while (std::cin >> n, n) {
        std::vector<std::string> s(n);
        for (int i = 0; i < n; ++i)
            std::cin >> s[i];
        int y = 0;
        std::cout << solve(s, n, y, 0) << std::endl;
    }
    return 0;
}