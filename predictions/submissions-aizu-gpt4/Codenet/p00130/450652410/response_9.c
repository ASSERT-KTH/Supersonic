#include <iostream>
#include <deque>
#include <string>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; ++i) {
        std::deque<char> train;
        std::string line;
        std::getline(std::cin, line);

        for (size_t j = 0; j < line.length(); j += 3) {
            if(line[j] == '<' && line[j+1] == '-') {
                train.push_front(line[j+2]);
            } else if(line[j] == '-' && line[j+1] == '>') {
                train.push_back(line[j+2]);
            }
        }

        for(const auto& c: train) {
            std::cout << c;
        }
        std::cout << '\n';

        if(std::cin.eof()) {
            break;
        }
    }

    return 0;
}