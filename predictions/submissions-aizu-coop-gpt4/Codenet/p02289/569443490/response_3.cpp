#include <iostream>
#include <queue>
#include <string>

int main() {
    std::priority_queue<int> heap;
    std::string command;
    while (std::cin >> command) {
        if (command == "end") {
            break;
        } else if (command[0] == 'i') {
            int data = std::stoi(command.substr(1));
            heap.push(data);
        } else {
            std::cout << heap.top() << std::endl;
            heap.pop();
        }
    }
}