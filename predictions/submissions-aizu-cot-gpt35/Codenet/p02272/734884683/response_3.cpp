#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

void inputArray(std::vector<uint32_t>& A) {
    for (auto& elem : A) {
        std::scanf("%u", &elem);
    }
}

void printArray(const std::vector<uint32_t>& A) {
    bool first = true;
    for (const auto& elem : A) {
        if (!first) {
            std::printf(" ");
        }
        std::printf("%u", elem);
        first = false;
    }
    std::printf("\n");
}

void merge(std::vector<uint32_t>& A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    
    std::vector<uint32_t> L(n1 + 1);
    std::vector<uint32_t> R(n2 + 1);
    
    std::copy(A.data() + left, A.data() + left + n1, L.data());
    std::copy(A.data() + mid, A.data() + mid + n2, R.data());
    
    L[n1] = R[n2] = std::numeric_limits<uint32_t>::max();
    
    for (int i = 0, j = 0, k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(std::vector<uint32_t>& A, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int n;
    std::scanf("%d", &n);
    
    std::vector<uint32_t> A(n);
    inputArray(A);
    
    mergeSort(A, 0, n);
    
    printArray(A);
    
    return 0;
}