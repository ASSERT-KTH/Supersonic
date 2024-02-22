#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

static inline void merge(uint32_t A[], uint32_t left, uint32_t mid, uint32_t right, int& compared) {
    uint32_t n1 = mid - left;
    uint32_t n2 = right - mid;
    uint32_t* L = new uint32_t[n1+1];
    uint32_t* R = new uint32_t[n2+1];
    copy(&A[left], &A[left + n1], L);
    copy(&A[mid], &A[mid + n2], R);
    L[n1] = R[n2] = UINT32_MAX;
    for (uint32_t i = 0, j = 0, k = left; k < right; k++) {
        compared++;
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
    delete[] L;
    delete[] R;
}

static inline void mergeSort(uint32_t A[], uint32_t left, uint32_t right, int& compared) {
    if (left + 1 < right) {
        uint32_t mid = (left + right) / 2;
        mergeSort(A, left, mid, compared);
        mergeSort(A, mid, right, compared);
        merge(A, left, mid, right, compared);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<uint32_t> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int compared = 0;
    mergeSort(&A[0], 0, n, compared);
    for (int i = 0; i < n; i++) {
        if (i != 0) cout << " ";
        cout << A[i];
    }
    cout << "\n" << compared << endl;
    return 0;
}