#include <iostream>
#include <array>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cout.precision(5);
    std::cout.setf(std::ios::fixed);

    auto isUsed = std::array<bool, 9>{};
    auto a = std::array<int, 18>{};
    auto b = std::array<int, 18>{};

    int n;
    std::cin >> n;

    while (n--) {
        for (int i = 0; i < 9; i++) {
            std::cin >> a[i];
            isUsed[i] = false;
        }
        for (int i = 0; i < 9; i++) {
            std::cin >> a[i + 9];
        }
        std::sort(a.begin(), a.end());

        double ans[2] = {0, 0};
        do {
            for (int i = 0; i < 9; i++) {
                b[i] = a[i];
                b[i + 9] = a[i + 9];
            }
            std::sort(b.begin(), b.begin() + 9);
            std::sort(b.begin() + 9, b.end());
            int sum[2] = {0, 0};
            for (int i = 0; i < 9; i++) {
                if (b[i] > b[i + 9]) sum[0] += b[i] + b[i + 9];
                else sum[1] += b[i] + b[i + 9];
            }
            if (sum[0] > sum[1]) ans[0]++;
            else if (sum[0] < sum[1]) ans[1]++;
        } while (std::next_permutation(a.begin(), a.end()));

        ans[0] /= 362880.0;
        ans[1] /= 362880.0;

        std::cout << ans[0] << ' ' << ans[1] << '\n';
    }

    return 0;
}