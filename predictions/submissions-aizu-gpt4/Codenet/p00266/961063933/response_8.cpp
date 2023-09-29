#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 100001
#define MOD 1000000007

long long factmodary[MAX_SIZE];
int word[MAX_SIZE];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long fact = 1;
    for (int i = 1; i < MAX_SIZE; i++) {
        fact = (fact * i) % MOD;
        factmodary[i] = fact;
    }  
    int N, R;
    while (std::cin >> N && N != 0) {
        std::cin >> R;
        for (int i = 0; i < N; ++i)
            word[i] = i + 1;
        while (R--) {
            int s, t;
            std::cin >> s >> t;
            std::swap(word[s - 1], word[t - 1]);
        }
        std::vector<int> bubblehist(N + 1, 0);
        for (int i = 0; i < N; ++i)
            bubblehist[word[i]] = i;
        long long ans = 0;
        for (int i = 0; i < N; ++i) {
            ans = (ans + (factmodary[N - i - 1] * (word[i] - 1 - bubblehist[word[i]])) % MOD) % MOD;
            for (int j = i + 1; j < N; ++j) {
                if (word[j] > word[i]) {
                    --bubblehist[word[j]];
                }
            }
        }
        std::cout << ans << '\n';
    }
    return 0;
}