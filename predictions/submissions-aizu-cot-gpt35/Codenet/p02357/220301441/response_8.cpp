#include <iostream>
#include <vector>

class StaticRMQ {
public:
    StaticRMQ(std::vector<uint32_t>& array) {
        this->array = array;
    }

    uint32_t operator()(uint32_t begin, uint32_t end) {
        uint32_t min_val = array[begin];
        for (uint32_t i = begin + 1; i <= end; i++) {
            if (array[i] < min_val) {
                min_val = array[i];
            }
        }
        return min_val;
    }

private:
    std::vector<uint32_t> array;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    uint32_t n, l;
    std::cin >> n >> l;
    std::vector<uint32_t> a(n);
    for (uint32_t i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    StaticRMQ S(a);
    std::cout << S(0, l);

    for (uint32_t i = 1; i <= n - l; i++) {
        std::cout << " " << S(i, i + l);
    }

    std::cout << "\n";
    return 0;
}