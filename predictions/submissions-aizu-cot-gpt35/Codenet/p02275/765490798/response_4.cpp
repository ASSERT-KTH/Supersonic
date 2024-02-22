#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_VALUE = 1000000;

void counting_sort(vector<int>& v) {
    int n = v.size();
    vector<int> cnt(MAX_VALUE + 1), tmp(n);
    for (int x : v)
        cnt[x]++;
    for (int i = 1; i <= MAX_VALUE; i++)
        cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        v[--cnt[tmp[i]]] = tmp[i];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    counting_sort(A);
    printf("%d", A[0]);
    for (int i = 1; i < A.size(); i++) {
        printf(" %d", A[i]);
    }
    printf("\n");
    return 0;
}