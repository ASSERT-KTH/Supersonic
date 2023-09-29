#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
  
    int n;
    std::string now, next;
    while (std::cin >> n, n) {
        int ans = 0;
        now = "";
        for(int i = 0; i < n; ++i) {
            std::cin >> next;
            if ((now == "lu" && next == "ru") || (now == "ru" && next == "lu") || 
                (now == "ld" && next == "rd") || (now == "rd" && next == "ld"))
                ++ans;
            now = std::move(next);
        }
        std::cout << ans << '\n';
    }
    return 0;
}