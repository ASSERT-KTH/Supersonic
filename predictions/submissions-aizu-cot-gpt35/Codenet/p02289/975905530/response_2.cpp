#include <iostream>
#include <queue>
#include <string>

int pop_and_print() {
    std::priority_queue<int> qu;
    std::cout << qu.top() << std::endl;
    qu.pop();
}

int main() {
    std::string s;
    int inp;
    while (true) {
        std::cin >> s;
        if (s == "insert") {
            std::cin >> inp;
            pop_and_print();
        } else {
            break;
        }
    }
    
    return 0;
}