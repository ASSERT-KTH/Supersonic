#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int arraySize;
    std::cin >> arraySize;

    std::vector<int> sequence1(arraySize), sequence2(arraySize);
    for(int& num : sequence1)
        std::cin >> num;

    int num;
    while(std::cin >> num) {
        sequence2.push_back(num);
    }

    std::vector<int> dp(arraySize+1);
    for(int x : sequence2) {
        int maxSoFar = 0, prev;
        for(int i=0; i<arraySize; i++) {
            prev = dp[i];
            if(x == sequence1[i])
                dp[i] = maxSoFar + 1;
            else if(maxSoFar < dp[i])
                maxSoFar = dp[i];
            dp[i] = prev;
        }
    }

    std::cout << *std::max_element(dp.begin(), dp.end()) << '\n';
    return 0;
}