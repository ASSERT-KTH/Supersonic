#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX 1000000001

long long merge(std::vector<int>&, int, int, int);
long long mergeSort(std::vector<int>&, int, int);

int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> S(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &S[i]);
    long long count = mergeSort(S, 0, n);
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", S[i]);
    }
    printf("\n%lld\n", count);
    return 0;
}

long long mergeSort(std::vector<int>& S, int left, int right) {
    if (right - left <= 1) return 0;
    int mid = (left + right) / 2;
    return mergeSort(S, left, mid) + mergeSort(S, mid, right) + merge(S, left, mid, right);
}

long long merge(std::vector<int>& S, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    std::vector<int> L(S.begin() + left, S.begin() + mid);
    std::vector<int> R(S.begin() + mid, S.begin() + right);
    L.push_back(MAX);
    R.push_back(MAX);
    int i = 0, j = 0;
    long long count = 0;
    for (int k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            S[k] = L[i++];
        } else {
            S[k] = R[j++];
            count += n1 - i;
        }
    }
    return count;
}