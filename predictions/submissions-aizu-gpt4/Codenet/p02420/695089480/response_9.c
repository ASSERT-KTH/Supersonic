#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    std::string s;
    int m, t, h;
    
    while (std::cin >> s, s[0] != '-') {
        std::cin >> m;
        std::vector<int> h(m);
        t = 0;
        for (int& hi : h) {
            std::cin >> hi;
            t += hi;
        }

        t %= s.size();

        if (t < 0) t += s.size();
        std::cout << (s.substr(t) + s.substr(0, t)) << "\n";
    }

    return 0;
}