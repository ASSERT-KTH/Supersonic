#include <queue>
#include <iostream>
#include <string>

int main() {
    std::priority_queue<int> heap;
    std::string input;
    while (std::getline(std::cin, input)) {
        if (input[2] == 'd')
            break;
        if (input[0] == 'i') {
            std::string numberAsString = input.substr(2);
            heap.push(std::stoi(numberAsString));
        } else {
            std::cout << heap.top() << std::endl;
            heap.pop();
        }
    }
    return 0;
}