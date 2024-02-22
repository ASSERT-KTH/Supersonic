#include <iostream>

int main() {
    int n, m;
    if (!(std::cin >> n >> m)) {
        std::cerr << "Error: Invalid input.\n";
        return 1;  // return non-zero value to indicate an error
    }

    std::cout << n - m - 1 << '\n';

    return 0;  // indicate that program ended successfully
}