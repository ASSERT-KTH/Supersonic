#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

void merge(int *A, int left, int mid, int right, int &cnt) {
    int n1 = mid - left;
    int n2 = right - mid;
    int i = 0, j = 0, k;
    for (k = left; k < right; k++) {
        if (i >= n1) {
            A[k] = A[mid + j++];
        } else if (j >= n2) {
            A[k] = A[left + i++];
        } else if (A[left + i] <= A[mid + j]) {
            A[k] = A[left + i++];
        } else {
            A[k] = A[mid + j++];
            cnt += n1 - i; // Count the number of inversions.
        }
    }
}

void mergesort(int *A, int left, int right, int &cnt) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergesort(A, left, mid, cnt);
        mergesort(A, mid, right, cnt);
        merge(A, left, mid, right, cnt);
    }
}

int main() {
    int N;
    cin >> N;
    int S[N];
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    int cnt = 0;
    mergesort(S, 0, N, cnt);
    string output;
    for (int i = 0; i < N; i++) {
        output += to_string(S[i]) + ' ';
    }
    cout << output << '\n' << cnt << '\n';
    return 0;
}