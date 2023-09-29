#include <iostream>
#include <deque>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::string line;
    std::getline(std::cin, line); // to consume '\n' after n

    while (n--) {
        std::getline(std::cin, line);
        std::deque<char> train;

        for (size_t i = 0; i < line.length(); i += 3) {
            if (line[i] == '<' && line[i + 1] == '-')
                train.push_front(line[i + 2]);
            else if (line[i] == '-' && line[i + 1] == '>')
                train.push_back(line[i + 2]);
        }

        for (const char& c: train)
            std::cout << c;

        std::cout << '\n';
    }

    return 0;
}