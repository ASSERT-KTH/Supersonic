#include <vector>
#include <string>
#include <numeric>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)

int solve(const std::vector<std::string> &s, int n, int &y, int x) {
    if (isdigit(s[y][x]))
        return s[y++][x] - '0';
    
    char op = s[y][x];
    ++y, ++x;
    
    std::vector<int> term;
    term.reserve(s.size());
    
    while (y < n && s[y].size() > static_cast<size_t>(x)) {
        term.push_back(solve(s, n, y, x));
    }
    
    if (op == '+')
        return std::accumulate(term.begin(), term.end(), 0);
    else
        return std::accumulate(term.begin(), term.end(), 1, std::multiplies<int>());
}

int main() {
    int n;
    
    while (std::cin >> n, n) {
        std::vector<std::string> s(n);
        rep(i, n) std::cin >> s[i];
        
        int y = 0;
        std::cout << solve(s, n, y, 0) << "\n";
    }
    
    return 0;
}