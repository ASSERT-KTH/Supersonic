#include <algorithm>
#include <iostream>

int main() {
    int values[6] = {0};
    for (int &v : values) std::cin >> v;
    std::sort(values, values + 4);
    std::sort(values + 4, values + 6, std::greater<int>());
    int ans = values[1] + values[2] + values[3] + values[4] + values[5];
    std::cout << ans << std::endl;
    return 0;
}