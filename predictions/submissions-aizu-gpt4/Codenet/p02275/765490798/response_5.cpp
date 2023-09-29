#include <iostream>
#include <vector>
#include <algorithm>

void counting_sort(std::vector<int> &v) {
    int max_val = *std::max_element(v.begin(), v.end());
    std::vector<int> count(max_val + 1, 0);
  
    for(auto& num : v)
        count[num]++;
  
    int index = 0;
    for(int i = 0; i <= max_val; ++i) {
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
    for(int i=0; i<n; ++i) { 
        std::cin >> A[i]; 
    }
    counting_sort(A);
    for(const auto& num : A) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
    return 0;
}