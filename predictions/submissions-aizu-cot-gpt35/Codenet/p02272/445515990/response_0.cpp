#include <iostream>
using namespace std;

const int INF = 1000000001;
const int MAX = 500000;

int cnt;
int S[MAX] = {0}, L[MAX / 2], R[MAX / 2];

void merge(int *A, int left, int mid, int right) {
    int i = 0, j = 0;
    int n1 = mid - left;
    int n2 = right - mid;

    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }

    for (int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }

    L[n1] = INF;
    R[n2] = INF;

    for (int k = 0; k < right; k++) {
        if (L[i] <= R[j]) {
            A[left + k] = L[i];
            i++;
        } else {
            A[left + k] = R[j];
            j++;
        }
    }
}

void mergesort(int *A, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergesort(A, left, mid);
        mergesort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    mergesort(S, 0, N);

    for (int i = 0; i < N; i++) {
        if (i == N - 1) {
            cout << S[i] << endl;
        } else {
            cout << S[i] << " ";
        }
    }

    return 0;
}