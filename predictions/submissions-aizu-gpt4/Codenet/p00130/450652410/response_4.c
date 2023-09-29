#include <iostream>
#include <deque>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::cin.ignore();

    while (n--) {
        std::deque<char> train;
        char a, b, c;
        while (std::cin.get(a) && a != '\n') {
            std::cin.get(b);
            std::cin.get(c);
            std::cin.ignore();

            if (a == '<' && b == '-') {
                train.push_front(c);
            } else if (a == '-' && b == '>') {
                train.push_back(c);
            }
        }
        for (char ch: train) {
            std::cout << ch;
        }
        std::cout << '\n';
    }

    return 0;
}