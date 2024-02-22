#include <iostream>
#include <vector>

int main() {
    long long n, min, max, sum = 0;
    std::cin >> n;
    std::vector<long long> a(n); // Preallocate space

    for (long long i = 0; i < n; i++) {
        std::cin >> a[i];
        if (i == 0) {
            min = max = a[i];
        } else {
            if (a[i] < min) min = a[i];
            if (a[i] > max) max = a[i];
        }
        sum += a[i];
    }

    std::cout << min << " " << max << " " << sum << std::endl;
}