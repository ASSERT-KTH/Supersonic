#include <iostream>
#include <queue>
#include <string>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::priority_queue<int> heap;
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line[2] == 'd') break;
        if (line[0] == 'i') {
            heap.push(std::stoi(line.substr(7)));
        } else {
            std::cout << heap.top() << "\n";
            heap.pop();
        }
    }
}