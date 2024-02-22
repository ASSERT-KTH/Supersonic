#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<int> numbers(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> numbers[i];
            sum += numbers[i];
        }
        
        std::sort(numbers.begin(), numbers.end());
        
        int max_value = 0;
        int running_sum = 0;
        for (int i = n - 1; i >= 0; --i) {
            running_sum += numbers[i];
            max_value = std::max(max_value, (i + 1) * running_sum);
        }
    }
    
    return 0;
}