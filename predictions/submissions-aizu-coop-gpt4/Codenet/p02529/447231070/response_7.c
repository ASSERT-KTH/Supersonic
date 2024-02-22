#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> inputs;
    int n, temp, count = 0;

    // Read the first set of integers.
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> temp;
        inputs.insert(temp);
    }

    // Read the second set of integers and count the ones that are in the first set.
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> temp;
        if (inputs.count(temp)) {
            ++count;
        }
    }

    std::cout << count << "\n";
    return 0;
}