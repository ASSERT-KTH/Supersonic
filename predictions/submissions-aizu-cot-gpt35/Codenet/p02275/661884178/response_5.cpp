#include <iostream>
#include <vector>
#include <climits>

int main() {
    int n;
    scanf("%d", &n);
    
    int min = INT_MAX;
    std::vector<int> A;
    
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if (t < min)
            min = t;
        A.push_back(t);
    }
    
    A[min]--;
    printf("%d", min);
    
    for (int i = min; i < A.size(); i++) {
        for (int j = 0; j < A[i]; j++) {
            printf(" %d", i);
        }
    }
    
    printf("\n");
    return 0;
}