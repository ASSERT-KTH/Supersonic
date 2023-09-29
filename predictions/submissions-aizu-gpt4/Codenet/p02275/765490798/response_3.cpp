#include <iostream>
#include <vector>
#include <algorithm>

void counting_sort(std::vector<int>& v) {
    int max = *std::max_element(v.begin(), v.end());
    std::vector<int> count(max + 1, 0);

    for(auto i : v) {
        count[i]++;
    }

    int index = 0;
    for(int i = 0; i < count.size(); i++) {
        while(count[i] > 0) {
            v[index] = i;
            index++;
            count[i]--;
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> A(n);
    for(int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    counting_sort(A);

    for(int i = 0; i < A.size(); i++) {
        std::cout << A[i] << " ";
    }
    std::cout << '\n';

    return 0;
}