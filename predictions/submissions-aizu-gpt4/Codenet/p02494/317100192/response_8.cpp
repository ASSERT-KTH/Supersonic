#include <iostream>
#include <string>

int main() {
    int h, w;
    while (std::cin >> h >> w && h && w) {
        std::string line(w, '#');
        for (int i = 0; i < h; i++)
            std::cout << line << '\n';
        std::cout << '\n';
    }
    return 0;
}