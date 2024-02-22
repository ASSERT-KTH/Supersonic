#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

void inputArray(vector<uint32_t>& A) {
    for (auto& elem : A) {
        cin >> elem;
    }
}

void printArray(const vector<uint32_t>& A) {
    for (int i = 0; i < A.size(); i++) {
        cout << (i != 0 ? " " : "") << A[i];
    }
    cout << endl;
}

void merge(vector<uint32_t>& A, uint32_t left, uint32_t mid, uint32_t right, uint32_t& compared, vector<uint32_t>& buffer) {
    uint32_t i, j, k;
    for(i = 0, k = left; k < mid; i++, k++) buffer[i] = A[k];
    for(j = 0, k = right; k > mid; j++, k--) A[k+j] = A[k];
    for(k = left; k < right; k++) {
        if(buffer[i] <= A[right-j-1]) {
            A[k] = buffer[i++];
        } else {
            A[k] = A[--right];
            compared += mid-left-i;
        }
    }
}

void mergeSort(vector<uint32_t>& A, uint32_t left, uint32_t right, uint32_t& compared, vector<uint32_t>& buffer) {
    if (right - left <= 1) return;
    uint32_t mid = (left + right) / 2;
    mergeSort(A, left, mid, compared, buffer);
    mergeSort(A, mid, right, compared, buffer);
    merge(A, left, mid, right, compared, buffer);
}

int main() {
    int n;
    cin >> n;
    vector<uint32_t> A(n), buffer(n);
    uint32_t compared = 0;
    inputArray(A);
    mergeSort(A, 0, n, compared, buffer);
    printArray(A);
    cout << compared << endl;
    return 0;
}