#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int size, x;
    std::cin >> size;

    std::vector<int> c(size+1), d(size+1);
    for(int i = 1; i <= size; ++i) {
        std::cin >> c[i];
    }

    int m = 0, t = 0, u = 0;
    while(std::cin >> x) {
        for (int i = 0; i++ < size; t = d[i], d[i] = std::min(m, u)) {
            u = (x - c[i]) ? u : t + 1;
        }
    }
    std::cout << m << "\n";

    return 0;
}