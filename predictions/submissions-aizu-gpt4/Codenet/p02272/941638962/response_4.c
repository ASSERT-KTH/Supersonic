#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<int> S(n);
    for(int& num : S) std::cin >> num;

    std::sort(S.begin(), S.end());
    
    for(int i = 0; i < n; ++i) {
        if(i != 0) std::cout << " ";
        std::cout << S[i];
    }
    std::cout << "\n" << n << "\n";
    return 0;
}