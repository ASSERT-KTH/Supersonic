#include <iostream>
#include <cstring>

int main() {
    std::ios_base::sync_with_stdio(false);
    char num[1001];
    while (1) {
        std::cin >> num;
        if (num[0] == '0')
            break;
        int sum = 0;
        int len = std::strlen(num);
        for (int i = 0; i < len; i++) {
            sum += num[i] - '0';
        }
        std::cout << sum << "\n";
    }
    return 0;
}