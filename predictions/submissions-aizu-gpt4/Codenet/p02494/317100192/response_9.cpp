#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int h, w;
    while (std::cin >> h >> w && h != 0 && w != 0) {
        std::cout << std::string(w, '#') << "\n";
    }
    return 0;
}