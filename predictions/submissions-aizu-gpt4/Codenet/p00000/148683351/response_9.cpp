#include <iostream>
#include <array>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::array <std::array<int, 9>, 9> arr;
    for(int i = 1; i <= 9; ++i)
        for(int j = 1; j <= 9; ++j)
            arr[i-1][j-1] = i*j;

    for(int i = 1; i <= 9; ++i)
        for(int j = 1; j <= 9; ++j)
            std::cout << i << "x" << j << "=" << arr[i-1][j-1] << '\n';
    return 0;
}