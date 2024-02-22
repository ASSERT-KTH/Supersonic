#include <iostream>
#include <vector>
#include <algorithm>

void counting_sort(std::vector<int>& v) {
    int n = v.size(), k = *std::max_element(v.begin(), v.end());
    std::vector<int> cnt(k + 1);
    cnt[0]--;
    for (int x : v)
        cnt[x]++;
    for (int i = 0; i < k; i++)
        cnt[i + 1] += cnt[i];
    for (int i = n - 1; i >= 0; i--) {
        v[cnt[v[i]]] = v[i];
        cnt[v[i]]--;
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> A(n);
    for(int i = 0; i < n; i++)
        std::cin >> A[i];
    counting_sort(A);
    for(const auto& val : A)
        std::cout << val << " ";
    std::cout << std::endl;
    return 0;
}