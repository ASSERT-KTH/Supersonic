#include <stdio.h>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int n;
    scanf("%d", &n);
    std::vector<int> S(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &S[i]);
    
    std::stable_sort(S.begin(), S.end());
    
    for (int i = 0; i < n; ++i) {
        if (i != 0) printf(" ");
        printf("%d", S[i]);
    }
    printf("\n%d\n", n);
    
    return 0;
}