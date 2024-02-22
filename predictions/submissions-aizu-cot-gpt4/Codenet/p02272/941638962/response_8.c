#include <iostream>
#include <vector>
#define MAX 1000000001
void mergesort(std::vector<int>&, int, int);
void merge(std::vector<int>&, int, int, int);
int count = 0;

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    std::vector<int> S(n);
    for (int i = 0; i < n; i++)
        std::cin >> S[i];
    mergesort(S, 0, n);
    for (int i = 0; i < n; i++) {
        std::cout << S[i];
        if (i != n - 1)
            std::cout << " ";
    }
    std::cout << "\n" << count << "\n";
    return 0;
}

void mergesort(std::vector<int>& S, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergesort(S, left, mid);
        mergesort(S, mid, right);
        merge(S, left, mid, right);
    }
}

void merge(std::vector<int>& S, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    std::vector<int> temp(n1 + n2 + 1);
    for (int i = 0; i < n1; i++)
        temp[i] = S[left + i];
    for (int i = 0; i < n2; i++)
        temp[n1 + i] = S[mid + i];
    temp[n1 + n2] = MAX;
    int i = 0, j = n1, k = left;
    while (k < right) {
        if (temp[i] <= temp[j])
            S[k++] = temp[i++];
        else
            S[k++] = temp[j++];
    }
    count += right - left;
}