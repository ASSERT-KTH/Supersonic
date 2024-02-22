#include <iostream>
#include <vector>

const int MAX_SIZE = 10001;

template<typename T>
void repeat(T func, int n) {
    for (int i = 0; i < n; ++i) func();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    int min = 2000000, t;
    std::vector<int> A(MAX_SIZE, 0);

    repeat([&]() {
        std::cin >> t;
        if (t < min) min = t;
        A[t]++;
    }, n);

    A[min]--;
    std::cout << min;

    for (int i = min; i < MAX_SIZE; ++i) {
        repeat([&]() { std::cout << ' ' << i; }, A[i]);
    }

    std::cout << '\n';
    return 0;
}