#include <iostream>
#include <deque>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::string line;
    std::getline(std::cin, line); // To consume the remaining newline character

    while(n--) {
        std::deque<char> train;
        std::getline(std::cin, line);

        for (size_t i = 0; i < line.size(); i += 3) {
            if(line[i] == '<' && line[i+1] == '-') train.push_front(line[i+2]);
            else if(line[i] == '-' && line[i+1] == '>') train.push_back(line[i+2]);
        }

        for (const auto& character : train) std::cout << character;
        std::cout << '\n';
    }

    return 0;
}